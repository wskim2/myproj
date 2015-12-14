
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long word;  // up to 32 bytes long
#define wsize sizeof(word)
#define wmask (wsize - 1)

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

void * memcpy_3(void *dst0, const void *src0, unsigned long length)
{

	if (length == 0 || dst0 == src0)		/* nothing to do */
      {
          printf("Error: do nothing, len=0 or dest = src!!!\n");
          return 0;
      }

	  if ((unsigned long)dst0 < (unsigned long)src0) { /* copy forward */
	    register unsigned long n = (length + 7) / 8;
	    register char *dst = dst0, *src = src0;

	    switch( length % 8 ) {
	    case 0:	do {	*dst++ = *src++;
	    case 7:		*dst++ = *src++;
	    case 6:		*dst++ = *src++;
	    case 5:		*dst++ = *src++;
	    case 4:		*dst++ = *src++;
	    case 3:		*dst++ = *src++;
	    case 2:		*dst++ = *src++;
	    case 1:		*dst++ = *src++;
	                    } while(--n > 0);
	    }
	  }
	  else { /* copy backward */
	    register unsigned long n = (length + 7) / 8;
	    register char *dst = dst0 + length, *src = src0 + length;

	    switch( length % 8 ) {
	    case 0:	do {	*--dst = *--src;
	    case 7:		*--dst = *--src;
	    case 6:		*--dst = *--src;
	    case 5:		*--dst = *--src;
	    case 4:		*--dst = *--src;
	    case 3:		*--dst = *--src;
	    case 2:		*--dst = *--src;
	    case 1:		*--dst = *--src;
	                    } while(--n > 0);
	    }

	  }
	  return dst0;
}



void dps_minimove_forward(char *dst, const char *src, unsigned int t)
{
	if (t) { dst[0] = src[0];
	if (t > 1) { dst[1] = src[1];
	if (t > 2) { dst[2] = src[2];
	if (t > 3) { dst[3] = src[3];
	if (t > 4) { dst[4] = src[4];
	if (t > 5) { dst[5] = src[5];
	if (t > 6) { dst[6] = src[6];
	if (t > 7) { dst[7] = src[7];
	if (t > 8 ) { dst[8] = src[8];
	if (t > 9) { dst[9] = src[9];
	if (t > 10) { dst[10] = src[10];
	if (t > 11) { dst[11] = src[11];
	if (t > 12) { dst[12] = src[12];
	if (t > 13) { dst[13] = src[13];
	if (t > 14) { dst[14] = src[14];
	if (t > 15) { dst[15] = src[15];
	if (t > 16) { dst[16] = src[16];
	if (t > 17) { dst[17] = src[17];
	if (t > 18) { dst[18] = src[18];
	if (t > 19) { dst[19] = src[19];
	if (t > 20) { dst[20] = src[20];
	if (t > 21) { dst[21] = src[21];
	if (t > 22) { dst[22] = src[22];
	if (t > 23) { dst[23] = src[23];
	if (t > 24) { dst[24] = src[24];
	if (t > 25) { dst[25] = src[25];
	if (t > 26) { dst[26] = src[26];
	if (t > 27) { dst[27] = src[27];
	if (t > 28) { dst[28] = src[28];
	if (t > 29) { dst[29] = src[29];
	if (t > 30) { dst[30] = src[30];
	}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}

void dps_minimove_backward(char *dst, char *src, unsigned int t)
{
	switch(t) {
	case 31: dst[30] = src[30];
	case 30: dst[29] = src[29];
	case 29: dst[28] = src[28];
	case 28: dst[27] = src[27];
	case 27: dst[26] = src[26];
	case 26: dst[25] = src[25];
	case 25: dst[24] = src[24];
	case 24: dst[23] = src[23];
	case 23: dst[22] = src[22];
	case 22: dst[21] = src[21];
	case 21: dst[20] = src[20];
	case 20: dst[19] = src[19];
	case 19: dst[18] = src[18];
	case 18: dst[17] = src[17];
	case 17: dst[16] = src[16];
	case 16: dst[15] = src[15];
	case 15: dst[14] = src[14];
	case 14: dst[13] = src[13];
	case 13: dst[12] = src[12];
	case 12: dst[11] = src[11];
	case 11: dst[10] = src[10];
	case 10: dst[9] = src[9];
	case 9: dst[8] = src[8];
	case 8: dst[7] = src[7];
	case 7: dst[6] = src[6];
	case 6: dst[5] = src[5];
	case 5: dst[4] = src[4];
	case 4: dst[3] = src[3];
	case 3: dst[2] = src[2];
	case 2: dst[1] = src[1];
	case 1: dst[0] = src[0];
	}
}

void * memcpy_4(char *dst0, char *src0, unsigned int length)
{
	unsigned int t;

  if (length == 0 || dst0 == src0)		/* nothing to do */
    return dst0;
  if ((unsigned long long)dst0 < (unsigned long long)src0) { /* copy forward */
    register char *dst = dst0, *src = src0;
    t = (unsigned int)src & wmask;
    if (t) {
    	if (length < wsize) {
		t = length;
    	} else {
		t = wsize - t;
    	}
	dps_minimove_forward(dst, src, t);
	length -= t;
	src += t; dst += t;
     }
     t = length / wsize;
     if (t) {
	register unsigned int n = (t + 7) / 8;
    	register unsigned int r = (t % 8);
	register word *wdst = (word*)dst, *wsrc = (word*)src;
    	if (r == 0) r = 8;
    	wdst[0] = wsrc[0];
    	if (r > 1) { wdst[1] = wsrc[1];
    	if (r > 2) { wdst[2] = wsrc[2];
    	if (r > 3) { wdst[3] = wsrc[3];
    	if (r > 4) { wdst[4] = wsrc[4];
    	if (r > 5) { wdst[5] = wsrc[5];
    	if (r > 6) { wdst[6] = wsrc[6];
    	if (r > 7) { wdst[7] = wsrc[7];
	}}}}}}}
    	wsrc += r; wdst += r;
    	while (--n > 0) {
    		wdst[0] = wsrc[0];
    		wdst[1] = wsrc[1];
    		wdst[2] = wsrc[2];
    		wdst[3] = wsrc[3];
    		wdst[4] = wsrc[4];
    		wdst[5] = wsrc[5];
    		wdst[6] = wsrc[6];
    		wdst[7] = wsrc[7];
    		wsrc += 8; wdst += 8;
    	}
 	dst = (char*)wdst; src = (char *)wsrc;
    }
    if ( (t = (length & wmask)) )
		dps_minimove_forward(dst, src, t);

  } else { /* copy backward */
    register char *dst = dst0 + length, *src = src0 + length;
    t = (unsigned int)src & wmask;
    if (t) {
	if (length < wsize) {
		t = length;
	}
	dst -= t; src -= t;
	length -= t;
	dps_minimove_backward(dst, src, t);
    }
    t = length / wsize;
    if (t) {
    	register unsigned int n = (t + 7) / 8;
    	register unsigned int r = (t % 8);
	register word *wdst = (word*)dst, *wsrc = (word*)src;
    	if (r == 0) r = 8;
	wsrc -= r; wdst -= r;
	switch(r) {
	case 8:wdst[7] = wsrc[7];
	case 7:wdst[6] = wsrc[6];
	case 6:wdst[5] = wsrc[5];
	case 5:wdst[4] = wsrc[4];
	case 4:wdst[3] = wsrc[3];
	case 3:wdst[2] = wsrc[2];
	case 2:wdst[1] = wsrc[1];
	case 1:wdst[0] = wsrc[0];
	}
     	while (--n > 0) {
		wsrc -= 8; wdst -= 8;
		wdst[7] = wsrc[7];
		wdst[6] = wsrc[6];
		wdst[5] = wsrc[5];
		wdst[4] = wsrc[4];
		wdst[3] = wsrc[3];
		wdst[2] = wsrc[2];
		wdst[1] = wsrc[1];
		wdst[0] = wsrc[0];
	}
	dst = (char*)wdst; src = (char*)wsrc;
    }
    t = length & wmask;
    dps_minimove_backward(dst - t, src - t, t);
 }
  return dst0;
}

int compare_result(void *dst, void * src, unsigned int len)
{
int i;

	for(i=0;i<len;i++)
	{
		if(memcmp((char *)dst, (char *)src,1) !=0)
		{
			printf("mem copy error....\n");
			return 0;
		}
		dst++; src++;
	}
	return 1;

}

int main()

{
    int i,j, res;
    int count = 3000;
    unsigned long length = 50000;
    char* sz1[1000];
    char* sz2[1000];
    clock_t start, end;   /* start and end times */
    void *buf;


    for( i=0; i<1000; i++ )
    {

        sz1[i] = (char *)malloc( length );
        sz2[i] = (char *)malloc( length );

        for( j=0; j<length; j++ )
        {

            sz1[i][j] = j;
            //sz2[i][j] = j;

        }

    }



    printf("execution time are: \n");
    start = clock();

    for( i=0; i<count; i++ )

    {

        buf = memcpy_1( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    res = compare_result(buf, sz1, length);
    printf( "res= %d, memcpy_1: %d msec\n", res, end );


    //2nd one
    start = clock();

    for( i=0; i<count; i++ )

    {

        buf = memcpy_2( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    res = compare_result(buf, sz1, length);
    printf( "res= %d, memcpy_2: %d msec\n", res, end );


 //2nd one
    start = clock();

    for( i=0; i<count; i++ )

    {

        buf = memcpy_3( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    res = compare_result(buf, sz1, length);
    printf( "res= %d, memcpy_3: %d msec\n", res, end );



    start = clock();

    for( i=0; i<count; i++ )

    {

        buf = memcpy_4( sz2[i%1000], sz1[i%1000], length );

    }

    end = clock() - start;

    res = compare_result(buf, sz1, length);
    printf( "res= %d, memcpy_4: %d msec\n", res, end );


/*

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
