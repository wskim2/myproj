#include <stdlib.h>
#include <stdio.h>

//recursive call 1
int Fibo(int n)
{
int sum;

if (n <= 1)
	return n;


sum = Fibo(n-1) + Fibo(n-2);

return sum;
}

//recursive call with memoization to save time
int F[51];
int Fibo2(int n)
{

if(F[n] != -1) //if we already calculated or know the value
	return F[n];

F[n] = Fibo2(n-1) + Fibo2(n-2);

return F[n];
}

//0 1 1 2 3 5 8 13 21 ....
void calc_fibonachi(void)

{
int i, n, num;

	printf(" enter n for fibonachi? ");
	scanf("%d", &n);

	for(i=0;i<51;i++)
		F[i] = -1;

	F[0]=0;
	F[1] =1;

	//num=Fibo2(n);
	num = Fibo(n);
	printf("Fibo of %d is %d \n ", n, num);

}




//recursive call 2
int factorial(int n)
{
	int mul;

	if(n==1)
		return 1;
	else
		mul = factorial(n-1)*n;

	return mul;

}
void sim_factorial()
{
	int n, res;

	printf(" enter n for factorial? ");
	scanf("%d", &n);

	res= factorial(n);
	printf("\n result of fact(%d) = %d\n", n, res);
}

int main()
{

	calc_fibonachi();
	sim_factorial();

	getch();
}
