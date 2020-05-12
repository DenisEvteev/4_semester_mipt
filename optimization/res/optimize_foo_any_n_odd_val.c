#include <stdio.h>
inline int bar(int) __attribute__((always_inline));
int foo(int, int);

#define N 50000

int main()
{

	int i;
	int r = 0;
	for (i = 0; i < N; ++i)
		r += foo(100001, -i);
	printf("%d\n",r);
	return 0;
}


int foo(int n, int t)
{

	int i;
	int r = 0;
	if( n < 2 )
	{
		return t;
	}

	r += 2 * t;
	if( n == 2 )
		return r;
	int mid = n / 2;
	int end = mid - 3;


	int help = 0, help1 = 0, help2 = 0;
	for (i = 2; i < end; i += 4)
	{
		r     += i + t +     bar(i + mid + t);
		help  += i + 1 + t + bar(i + 1 + mid + t);
		help1 += i + 2 + t + bar(i + 2 + mid + t);
		help2 += i + 3 + t + bar(i + 3 + mid + t);


	}

	for(; i < mid; ++i){
		help += i + t;
		r += bar( i + mid + t);
	}

	if (n % 2 != 0){
		r += bar(n - 1 + t);
		if(n == 3)
			return r;
	}

	r += bar(mid + t);
	help += bar(1 + mid + t);
	r += help + help1 + help2;

	return r;
}

int bar(int x)
{
	return x > 1 ? x : 0;
}
