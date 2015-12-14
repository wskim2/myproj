/*
   to find a prime number
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
int cnt=0, m, n, i,j, primes[300];

	printf("find prime(<300) ? ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
		primes[i]=1;

	primes[0]=0;
	primes[1]=0;

	m = sqrt(n);

	for(i=2; i<= m;i++)
	{
		if(primes[i] == 1)
		for(j=2;i*j <= n;j++)
			primes[i*j] = 0;
	}

	for(i=0;i<=n;i++)
	{
		if(primes[i] == 1)
		{
			printf(" %d", i);
			cnt++;
			if(cnt%10 == 0)
				printf("\n");
		}
		
	}
	printf("\ntotal num. of primes are %d", cnt);
	getch();
}
