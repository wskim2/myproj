/*
	endian test to check endian of processors
*/

#include <stdio.h>
#include <stdlib.h>

void endian_test1()
{
union{
	unsigned int num;
	unsigned char bytes[sizeof(unsigned int)];
	}u;
int i;

	u.num = 0x0a0b0c0d;

	for(i=0;i<sizeof(unsigned int);i++)
		printf("%x: %.2x\n", &u.bytes[i], u.bytes[i]);

	printf("Check byte sequence...\n");
}

void endian_test2()
{
	unsigned int num=1;
	
	if(*(char*)&num == 1)
		printf("\nLittel Endian\n");
	else
		printf("\nBig Endian\n");

}

void endian_test3()
{
	unsigned int num=1;

	if(*(char*)&num == 1)
		printf("\nLittel Endian\n");
	else
		printf("\nBig Endian\n");

}


int endian_conversion(unsigned char endian, unsigned int num)
{
unsigned int b0,b1,b2,b3;
unsigned int res, swapped;

b0 = (num & 0x000000ff) << 24u;
b1 = (num & 0x0000ff00) << 8u;
b2 = (num & 0x00ff0000) >> 8u;
b3 = (num & 0xff000000) >> 24u;

res = b0 | b1 | b2 | b3;
printf("converted endian from 0x%x to 0x%x\n", num, res);

/* 2nd swap number */
swapped =((num>>24)&0xff) | // move byte 3 to byte 0
         ((num<<8)&0xff0000) | // move byte 1 to byte 2
         ((num>>8)&0xff00) | // move byte 2 to byte 1
         ((num<<24)&0xff000000);// byte 0 to byte 3

printf("converted endian from 0x%x to 0x%x\n", num, res);
}


void main()
{
	 
	 endian_conversion(1, 0x123456);
	 endian_test2();

	 getch();
}
