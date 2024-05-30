#include "sources.hpp"

//int fibonacci(unsigned int n)
//{
//	if (n < 3) return 1;
//	return fibonacci(n - 1) + fibonacci(n - 2);
//}

void fibonacci(unsigned n, unsigned i, unsigned f1, unsigned f2)
{
	if (i > n) return;
	std::cout << f1 << std::endl;
	int f3 = f1 + f2;
	f1 = f2;
	f2 = f3;
	fibonacci(n, i + 1, f1, f2);
}

void natural_numbers(unsigned n)
{
	for (unsigned i = 1; i < n + 1; ++i)
	{
		std::cout << i << std::endl;
	}
}

void random_numbers(unsigned n)
{
	srand(time(0));
	for (unsigned i = 0; i < n; ++i)
	{
		std::cout << rand() << std::endl;
	}
}