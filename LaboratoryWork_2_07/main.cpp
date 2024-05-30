#include "sources.hpp"

//using namespace std::this_thread;


int main()
{
	/*std::thread1;
	std::thread2*/
	fibonacci(10);

	random_numbers(10);

	natural_numbers(10);
	//std::cout << fibonacci(10) << std::endl;

	//int n1, n2, n3;
	//std::cin >> n1 >> n2 >> n3;

	std::cout << std::this_thread::get_id();

	return 0;
	//unsigned int std::thread::hardware_concurrency();
}