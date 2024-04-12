#include "sources.hpp"

int main()
{
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	std::vector<Employee> vector_employee = readData(inputFile);

	for (const Employee employee : vector_employee)
	{
		std::cout << employee;
	}
	std::cout << std::endl << std::endl;

	std::deque<Employee> deque_employee(vector_employee.size());

	std::copy(vector_employee.cbegin(), vector_employee.cend(), deque_employee.begin());

	for (const Employee employee : deque_employee)
	{
		std::cout << employee;
	}
	std::cout << std::endl << std::endl;

	//std::sort(deque_employee.begin(), deque_employee.end(), [](const Employee& firstEmployee, const Employee& secondEmployee) -> bool {return firstEmployee.getName() < secondEmployee.getName(); }); // ןמקולף כמלאועסÿ ס סbegin() ט סend() גלוסעו ט ןמ מעהוכüםמסעט

	std::sort(deque_employee.begin(), deque_employee.end());


	for (const Employee employee : deque_employee)
	{
		std::cout << employee;
	}

	for (const Employee employee : deque_employee)
	{
		outputFile << employee;
	}

	outputFile.close();

	return 0;
}