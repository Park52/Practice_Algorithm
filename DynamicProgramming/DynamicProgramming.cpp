#include <stdio.h>

int d[100];

long long dp(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 1;
	//연산 횟수 2^50....

	if (d[x] != 0) return d[x];


	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void)
{
	printf("%lu\n", dp(30));
	
	return 0;
}