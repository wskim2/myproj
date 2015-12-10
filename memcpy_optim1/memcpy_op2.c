// aaa.cpp : Defines the entry point for the console application.

//


/*


MMX는FPU 레지스터를이용하는것인데FPU를안쓴다니무슨뜻인지

모르겠습니다. 매뉴얼을좀더자세히읽어보시길바랍니다. 그리고emms

명령이100클럭이소요된다는근거는어디에있는것인가요? 물론수킬로

바이트정도의작은데이터를복사하는데MMX나SSE를쓰는것은어리석은

일임은이미증명되어있습니다. :)


일반i386 명령으로1024바이트를복사하는데15000클럭이소요되고,

MMX 명령으로같은바이트를복사하는데25000클럭이소요되었다고

하면어느쪽이빠른코드인지는자명하지않나요? 이게의미없는

통계라면최적화자체가무의미합니다.


가령8바이트를한꺼번에복사하는movq같은

명령은그자체로보면일반적인4바이트복사명령인mov를2번쓰는

것보다이론적으로는최고2배, 또는적어도몇십%는빠를것같은예감이

들지만, 실제로는거꾸로수십배나느렸습니다(물론또특수한경우에서는

몇배빠르다고했지만그런경우는아직발견할수없었습니다). 이현상을

가져오는여러가지원인중제가짐작할수있었던것은MMX 명령어의긴

길이, 파이프라인에서의문제, 캐쉬라인, 셋업시간같은것들뿐입니다.

그러나프로세서내부의동작은제조사의기밀에해당하는문제이므로,

외부적으로는분석하기가매우어려울것입니다.


http://www.kr.freebsd.org/ml/archive/hackers/2001/10/msg00023.shtml

http://www.kr.freebsd.org/ml/archive/hackers/2001/10/msg00050.shtml


*/




#include "stdafx.h"
#include "aaa.h"
#include "mmsystem.h"
#include "Global.h"


#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif


/////////////////////////////////////////////////////////////////////////////

// The one and only application object


CWinApp theApp;


using namespace std;


void memcpy3( void* dest, void* src, int num )

{

    if (num <= 0) return;



    _asm

    {

        mov edi, dest;    // 목적지저장

        mov esi, src;        // 소스저장

        mov ecx, num;        // 반복회수

        mov edx, ecx;        // 반복횟수복사(스텍->스텍이빠르다.)

        shr ecx, 1;        // dword 복사하므로/4 해야하므로쉬프트한다.

        shr ecx, 1;        // ...

        cld;                // 복사순서설정

        rep movsd;        // DWORD 단위복사


        mov ecx, edx;        // 저장해둔크기위치복구

        and ecx, 0x03;    // 크기% 4 한값얻기(하위비트)

        rep movsb;        // 바이트단위복사

    }

}


void memcpy2( void* dest, void* src, int num )

{

    if (num <= 0) return;



    _asm

    {

        mov edi, dest;    // 목적지저장

        mov esi, src;        // 소스저장

        mov ecx, num;        // 반복회수

        mov edx, ecx;        // 반복횟수복사(스텍->스텍이빠르다.)

        shr ecx, 2;        // dword 복사하므로/4 해야하므로쉬프트한다.

        cld;                // 복사순서설정

        rep movsd;        // DWORD 단위복사


        mov ecx, edx;        // 저장해둔크기위치복구

        and ecx, 0x03;    // 크기% 4 한값얻기(하위비트)

        rep movsb;        // 바이트단위복사

    }

}


int main(int argc, TCHAR* argv[], TCHAR* envp[])

{

    initGlobal();


    int i,j;

    int count = 3000;

    int length = 50000;


    char* sz1[1000];

    char* sz2[1000];


    for( i=0; i<1000; i++ )

    {

        sz1[i] = new char[ length ];

        sz2[i] = new char[ length ];


        for( j=0; j<length; j++ )

        {

            sz1[i][j] = j;

            sz2[i][j] = j;

        }

    }


    DWORD start, end;


    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        memcpy3( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "memcpy3: %d\n", end );


    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        memcpy2( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "memcpy2: %d\n", end );


    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        memcpy( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "memcpy: %d\n", end );


    // globals.h -- 그다지최적화되지않은MMX FPS 코드....

    setFPUcpy();

    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        fastcpy( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "setFPUcpy: %d\n", end );


    setMMXcpy();

    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        fastcpy( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "setMMXcpy: %d\n", end );


    for( i=0; i<1000; i++ )

    {

        delete[] sz1[i];

        delete[] sz2[i];

    }

    Sleep(1000);


    return 0;

}

