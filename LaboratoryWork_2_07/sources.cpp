#include "sources.hpp"

//int fibonacci(unsigned int n)
//{
//	if (n < 3) return 1;
//	return fibonacci(n - 1) + fibonacci(n - 2);
//}

void fibonacci(unsigned int n, unsigned int i = 1, unsigned int f1 = 1, unsigned int f2 = 1)
{
	if (i > n) return;
	std::cout << f1 << std::endl;
	int f3 = f1 + f2;
	f1 = f2;
	f2 = f3;
	fibonacci(n, i + 1, f1, f2);
}