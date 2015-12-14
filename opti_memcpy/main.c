
// aaa.cpp : Defines the entry point for the console application.

//



/*



MMX\B4\C2FPU \B7\B9\C1\F6\BD\BA\C5͸\A6\C0̿\EB\C7ϴ°\CD\C0ε\A5FPU\B8\A6\BEȾ\B4\B4ٴϹ\AB\BD\BC\B6\E6\C0\CE\C1\F6

\B8𸣰ڽ\C0\B4ϴ\D9. \B8Ŵ\BA\BE\F3\C0\BB\C1\BB\B4\F5\C0ڼ\BC\C8\F7\C0о\BDñ\E6\B9ٶ\F8\B4ϴ\D9. \B1׸\AE\B0\EDemms

\B8\ED\B7\C9\C0\CC100Ŭ\B7\B0\C0̼ҿ\E4\B5ȴٴ±ٰŴ¾\EE\B5\F0\BF\A1\C0ִ°\CD\C0ΰ\A1\BF\E4? \B9\B0\B7м\F6ų\B7\CE

\B9\D9\C0\CCƮ\C1\A4\B5\B5\C0\C7\C0\DB\C0\BA\B5\A5\C0\CC\C5͸\A6\BA\B9\BB\E7\C7ϴµ\A5MMX\B3\AASSE\B8\A6\BE\B2\B4°\CD\C0\BA\BE\BC\AE\C0\BA

\C0\CF\C0\D3\C0\BA\C0̹\CC\C1\F5\B8\ED\B5Ǿ\EE\C0ֽ\C0\B4ϴ\D9. :)



\C0Ϲ\DDi386 \B8\ED\B7\C9\C0\B8\B7\CE1024\B9\D9\C0\CCƮ\B8\A6\BA\B9\BB\E7\C7ϴµ\A515000Ŭ\B7\B0\C0̼ҿ\E4\B5ǰ\ED,

MMX \B8\ED\B7\C9\C0\B8\B7ΰ\B0\C0\BA\B9\D9\C0\CCƮ\B8\A6\BA\B9\BB\E7\C7ϴµ\A525000Ŭ\B7\B0\C0̼ҿ\E4\B5Ǿ\FA\B4ٰ\ED

\C7ϸ\E9\BE\EE\B4\C0\C2\CA\C0̺\FC\B8\A5\C4ڵ\E5\C0\CE\C1\F6\B4\C2\C0ڸ\ED\C7\CF\C1\F6\BEʳ\AA\BF\E4? \C0̰\D4\C0ǹ̾\F8\B4\C2

\C5\EB\B0\E8\B6\F3\B8\E9\C3\D6\C0\FBȭ\C0\DAü\B0\A1\B9\AB\C0ǹ\CC\C7մϴ\D9.



\B0\A1\B7\C98\B9\D9\C0\CCƮ\B8\A6\C7Ѳ\A8\B9\F8\BF\A1\BA\B9\BB\E7\C7ϴ\C2movq\B0\B0\C0\BA

\B8\ED\B7\C9\C0\BA\B1\D7\C0\DAü\B7κ\B8\B8\E9\C0Ϲ\DD\C0\FB\C0\CE4\B9\D9\C0\CCƮ\BA\B9\BB\E7\B8\ED\B7\C9\C0\CEmov\B8\A62\B9\F8\BE\B2\B4\C2

\B0ͺ\B8\B4\D9\C0̷\D0\C0\FB\C0\B8\B7δ\C2\C3ְ\ED2\B9\E8, \B6Ǵ\C2\C0\FB\BE\B8\EE\BD\CA%\B4º\FC\B8\A6\B0Ͱ\B0\C0\BA\BF\B9\B0\A8\C0\CC

\B5\E9\C1\F6\B8\B8, \BD\C7\C1\A6\B7δ°Ųٷμ\F6\BDʹ質\B4\C0\B7Ƚ\C0\B4ϴ\D9(\B9\B0\B7ж\C7Ư\BC\F6\C7Ѱ\E6\BF쿡\BC\AD\B4\C2

\B8\EE\B9\E8\BA\FC\B8\A3\B4ٰ\ED\C7\DF\C1\F6\B8\B8\B1׷\B1\B0\E6\BF\EC\B4¾\C6\C1\F7\B9߰\DF\C7Ҽ\F6\BE\F8\BE\FA\BD\C0\B4ϴ\D9). \C0\CC\C7\F6\BB\F3\C0\BB

\B0\A1\C1\AE\BF\C0\B4¿\A9\B7\AF\B0\A1\C1\F6\BF\F8\C0\CE\C1\DF\C1\A6\B0\A1\C1\FC\C0\DB\C7Ҽ\F6\C0־\FA\B4\F8\B0\CD\C0\BAMMX \B8\ED\B7ɾ\EE\C0Ǳ\E4

\B1\E6\C0\CC, \C6\C4\C0\CC\C7\C1\B6\F3\C0ο\A1\BC\AD\C0ǹ\AE\C1\A6, ĳ\BD\AC\B6\F3\C0\CE, \BC¾\F7\BDð\A3\B0\B0\C0\BA\B0͵\E9\BB\D3\C0Դϴ\D9.

\B1׷\AF\B3\AA\C7\C1\B7μ\BC\BC\AD\B3\BB\BA\CE\C0ǵ\BF\C0\DB\C0\BA\C1\A6\C1\B6\BB\E7\C0Ǳ\E2\B9п\A1\C7ش\E7\C7ϴ¹\AE\C1\A6\C0̹Ƿ\CE,

\BFܺ\CE\C0\FB\C0\B8\B7δºм\AE\C7ϱⰡ\B8ſ\EC\BE\EE\B7\C1\BF\EF\B0\CD\C0Դϴ\D9.



http://www.kr.freebsd.org/ml/archive/hackers/2001/10/msg00023.shtml

http://www.kr.freebsd.org/ml/archive/hackers/2001/10/msg00050.shtml



*/







//#include "stdafx.h"

//#include "aaa.h"

#include <stdio.h>
#include <stdlib.h>
//#include <mmsystem.h>

//#include "Global.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif



/////////////////////////////////////////////////////////////////////////////

// The one and only application object

void _FastMemcpy(unsigned char * pDes, unsigned char* pSrc, unsigned long nCopySize)

{

     --pDes; --pSrc;


     switch(nCopySize& 7)

     {

     case0:

         do {

                 *(++pDes) = *(++pSrc); --nCopySize;

             case7: *(++pDes) = *(++pSrc); --nCopySize;

             case6: *(++pDes) = *(++pSrc); --nCopySize;

             case5: *(++pDes) = *(++pSrc); --nCopySize;

             case4: *(++pDes) = *(++pSrc); --nCopySize;

             case3: *(++pDes) = *(++pSrc); --nCopySize;

             case2: *(++pDes) = *(++pSrc); --nCopySize;

             case1: *(++pDes) = *(++pSrc); --nCopySize;

         }while(nCopySize);

     }

}



void memcpy3( void* dest, void* src, int num )

{

    if (num <= 0) return;


    _asm_

    ( \
        "cld\n" \
        "rep\n" \
        "movsl" \
        : \
        : "S" (src), "D"(dest),"c" (num)\
        : "%ecx", "%esi", "%edi" \
    );
/*
    _asm_

    (

        "mov edi, dest;"    // \B8\F1\C0\FB\C1\F6\C0\FA\C0\E5

        "mov esi, src;"        // \BCҽ\BA\C0\FA\C0\E5

        "mov ecx, num;"      // \B9ݺ\B9ȸ\BC\F6

        "mov edx, ecx;"        // \B9ݺ\B9Ƚ\BC\F6\BA\B9\BB\E7(\BD\BA\C5\D8->\BD\BA\C5\D8\C0̺\FC\B8\A3\B4\D9.)

        "shr ecx, 1;"        // dword \BA\B9\BB\E7\C7ϹǷ\CE/4 \C7ؾ\DF\C7ϹǷν\AC\C7\C1Ʈ\C7Ѵ\D9.

        "shr ecx, 1;"        // ...

        "cld;"                // \BA\B9\BB\E7\BC\F8\BC\AD\BC\B3\C1\A4

        "rep movsd;"        // DWORD \B4\DC\C0\A7\BA\B9\BB\E7



        "mov ecx, edx;"        // \C0\FA\C0\E5\C7ص\D0ũ\B1\E2\C0\A7ġ\BA\B9\B1\B8

        "and ecx, 0x03;"    // ũ\B1\E2% 4 \C7Ѱ\AA\BE\F2\B1\E2(\C7\CF\C0\A7\BA\F1Ʈ)

        "rep movsb;"        // \B9\D9\C0\CCƮ\B4\DC\C0\A7\BA\B9\BB\E7

    );
*/

}



void memcpy2( void* dest, void* src, int num )

{

    if (num <= 0) return;


/*
    _asm_

    (

        "mov edi, dest;"    // \B8\F1\C0\FB\C1\F6\C0\FA\C0\E5

        "mov esi, src;"        // \BCҽ\BA\C0\FA\C0\E5

        "mov ecx, num;"        // \B9ݺ\B9ȸ\BC\F6

        "mov edx, ecx;"        // \B9ݺ\B9Ƚ\BC\F6\BA\B9\BB\E7(\BD\BA\C5\D8->\BD\BA\C5\D8\C0̺\FC\B8\A3\B4\D9.)

        "shr ecx, 2;"       // dword \BA\B9\BB\E7\C7ϹǷ\CE/4 \C7ؾ\DF\C7ϹǷν\AC\C7\C1Ʈ\C7Ѵ\D9.

        "cld;"                // \BA\B9\BB\E7\BC\F8\BC\AD\BC\B3\C1\A4

        "rep movsd;"        // DWORD \B4\DC\C0\A7\BA\B9\BB\E7



        "mov ecx, edx;"        // \C0\FA\C0\E5\C7ص\D0ũ\B1\E2\C0\A7ġ\BA\B9\B1\B8

        "and ecx, 0x03;"    // ũ\B1\E2% 4 \C7Ѱ\AA\BE\F2\B1\E2(\C7\CF\C0\A7\BA\F1Ʈ)

        "rep movsb;"        // \B9\D9\C0\CCƮ\B4\DC\C0\A7\BA\B9\BB\E7

    );
*/
}



int main(int argc, char* argv[], char* envp[])

{
    int start, end;

    int i,j;

    int count = 3000;

    int length = 50000;



    char* sz1[1000];

    char* sz2[1000];


    initGlobal();

    for( i=0; i<1000; i++ )

    {

        sz1[i] = malloc(sizeof(char *));

        sz2[i] = malloc(sizeof(char *));



        for( j=0; j<length; j++ )

        {

            sz1[i][j] = j;

            sz2[i][j] = j;

        }

    }






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



    // globals.h -- \B1״\D9\C1\F6\C3\D6\C0\FBȭ\B5\C7\C1\F6\BE\CA\C0\BAMMX FPS \C4ڵ\E5....

    setFPUcpy();

    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        fastcpy( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "setFPUcpy: %d\n", end );



    //setMMXcpy();

    start = timeGetTime();

    for( i=0; i<count; i++ )

    {

        fastcpy( sz2[i%1000], sz1[i%1000], length );

    }

    end = timeGetTime() - start;

    printf( "setMMXcpy: %d\n", end );



    for( i=0; i<1000; i++ )

    {

        free(sz1[i]);

        free(sz2[i]);

    }

    Sleep(1000);



    return 0;

}
