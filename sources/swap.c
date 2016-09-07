#include <stdio.h>

void	swap(int *a, int *b)
{
int	tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

int	main(void)
{
	int a;
	int b;
	a = 42;
	b = 28;
	printf("adress of a [%p] value of a [%d]\n adress of b [%p], value of b [%d]\n", &a, a, &b, b);
	swap(&a, &b);
	printf("ADRESSES AND VALUES AFTER SWAP\n");
	printf("adress of a [%p] value of a [%d]\n adress of b [%p], value of b [%d]", &a, a, &b, b);

	return (0);
}
