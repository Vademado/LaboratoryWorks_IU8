#include "sources.h"

void laba_2()
{
	for (float eps = 1e-2; eps > 1e-7; eps /= 10)
	{
		int quantity_iteration = 1;
		float x = 1;
		float lim = sin(x) / x;
		double a = 1 - lim;
		while (fabs(1 - lim) >= eps)
		{
			quantity_iteration++;
			x /= 2;
			lim = sin(x) / x;
			std::cout << fabs(1 - lim) << "   " << eps << std::endl;
		}
		std::cout << "При eps=" << eps << " количество операций:" << quantity_iteration << std::endl;
	}
}