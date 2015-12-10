#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void * memcpy_1(void * dst, void const * src, unsigned long len)
 {
     char * pDst = (char *) dst;
     char const * pSrc = (char const *) src;


     while (len--)
     {
         *pDst++ = *pSrc++;
     }

     return (dst);
 }

 void * memcpy_2(void * dst, void const * src, unsigned long len)
 {
     char * pcDst;
     char const * pcSrc;
     long * plDst = (long *) dst;
     long const * plSrc = (long const *) src;
     long addr=0xFFFFFFFC;

     if (!(*plSrc & 0xFFFFFFFC) && !(*plDst & 0xFFFFFFFC))
     {
         while (len >= 4)
         {
             *plDst++ = *plSrc++;
             len -= 4;
         }
     }

     pcDst = (char *) plDst;
     pcSrc = (char const *) plSrc;


     while (len--)
     {
         *pcDst++ = *pcSrc++;
     }

     return (dst);
 }

void memcpy_3(void * plDst, void* plSrc, unsigned long nCopySize)
{
    long * pDes = (long *) plDst;
    long const * pSrc = (long const *) plSrc;

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


int main()

{



    int i,j;
    int count = 3000;
    unsigned long length = 50000;
    char* sz1[1000];
    char* sz2[1000];
    clock_t start, end;   /* start and end times */



    for( i=0; i<1000; i++ )

    {

        sz1[i] = (char *)malloc( length );

   	 sz2[i] = (char *)malloc( length );

        for( j=0; j<length; j++ )

        {

            sz1[i][j] = j;

            sz2[i][j] = j;

        }

    }


    //1st one

    start = clock();

    for( i=0; i<count; i++ )

    {

        memcpy_1( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    printf( "memcpy3: %i\n", end );


    //2nd one
    start = clock();

    for( i=0; i<count; i++ )

    {

        memcpy_2( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    printf( "memcpy2: %i\n", end );


 //2nd one
    start = clock();

    for( i=0; i<count; i++ )

    {

        memcpy_3( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    printf( "memcpy2: %i\n", end );


/*

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
   */

    //sleep(1000);
    getchar();

    return 0;

}
