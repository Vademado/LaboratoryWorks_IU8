#include "sources.hpp"

int main()
{
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	std::vector<Employee> vector_employee  = readData(inputFile);

	std::set<Employee> set_employee;

	std::copy(vector_employee.begin(), vector_employee.end(), std::inserter(set_employee, set_employee.begin()));

	for (const Employee employee : set_employee) {
		outputFile << employee <<std::endl;
	}

	outputFile.close();

	return 0;
}