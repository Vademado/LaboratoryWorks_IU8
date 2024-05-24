#include "sources.hpp"

int main()
{
	// MyUnique

	int* int_ptr = new int(5);

	MyUnique<int> unique_ptr = Make_MyUnique<int>(int_ptr);

	//std::cout << unique_ptr.get() << std::endl;

	return 0;
}