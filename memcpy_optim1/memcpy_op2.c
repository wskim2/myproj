// aaa.cpp : Defines the entry point for the console application.

//


/*


MMX��FPU �������͸��̿��ϴ°��ε�FPU���Ⱦ��ٴϹ���������

�𸣰ڽ��ϴ�. �Ŵ����������ڼ����о�ñ�ٶ��ϴ�. �׸���emms

�����100Ŭ���̼ҿ�ȴٴ±ٰŴ¾���ִ°��ΰ���? ���м�ų��

����Ʈ���������������͸������ϴµ�MMX��SSE�����°��������

�������̹�����Ǿ��ֽ��ϴ�. :)


�Ϲ�i386 �������1024����Ʈ�������ϴµ�15000Ŭ���̼ҿ�ǰ�,

MMX ������ΰ�������Ʈ�������ϴµ�25000Ŭ���̼ҿ�Ǿ��ٰ�

�ϸ������̺����ڵ��������ڸ������ʳ���? �̰��ǹ̾���

���������ȭ��ü�����ǹ��մϴ�.


����8����Ʈ���Ѳ����������ϴ�movq����

���������ü�κ����Ϲ�����4����Ʈ��������mov��2������

�ͺ����̷������δ��ְ�2��, �Ǵ�������%�º����Ͱ���������

������, �����δ°Ųٷμ��ʹ質���Ƚ��ϴ�(���ж�Ư���Ѱ�쿡����

�������ٰ��������׷����¾����߰��Ҽ��������ϴ�). ��������

�������¿����������������������Ҽ��־�������MMX ��ɾ��Ǳ�

����, ���������ο����ǹ���, ĳ������, �¾��ð������͵���Դϴ�.

�׷������μ��������ǵ������������Ǳ�п��ش��ϴ¹����̹Ƿ�,

�ܺ������δºм��ϱⰡ�ſ�������Դϴ�.


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

        mov edi, dest;    // ����������

        mov esi, src;        // �ҽ�����

        mov ecx, num;        // �ݺ�ȸ��

        mov edx, ecx;        // �ݺ�Ƚ������(����->�����̺�����.)

        shr ecx, 1;        // dword �����ϹǷ�/4 �ؾ��ϹǷν���Ʈ�Ѵ�.

        shr ecx, 1;        // ...

        cld;                // �����������

        rep movsd;        // DWORD ��������


        mov ecx, edx;        // �����ص�ũ����ġ����

        and ecx, 0x03;    // ũ��% 4 �Ѱ����(������Ʈ)

        rep movsb;        // ����Ʈ��������

    }

}


void memcpy2( void* dest, void* src, int num )

{

    if (num <= 0) return;



    _asm

    {

        mov edi, dest;    // ����������

        mov esi, src;        // �ҽ�����

        mov ecx, num;        // �ݺ�ȸ��

        mov edx, ecx;        // �ݺ�Ƚ������(����->�����̺�����.)

        shr ecx, 2;        // dword �����ϹǷ�/4 �ؾ��ϹǷν���Ʈ�Ѵ�.

        cld;                // �����������

        rep movsd;        // DWORD ��������


        mov ecx, edx;        // �����ص�ũ����ġ����

        and ecx, 0x03;    // ũ��% 4 �Ѱ����(������Ʈ)

        rep movsb;        // ����Ʈ��������

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


    // globals.h -- �״�������ȭ��������MMX FPS �ڵ�....

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

