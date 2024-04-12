#include "sources.hpp"

EmployeeCompany::EmployeeCompany()
{
	this->fullname = "";
	this->salary = 0;
	this->salary_supplement = 0;
}

EmployeeCompany::EmployeeCompany(std::string fullname, unsigned int salary, short salary_supplement)
{
	this->fullname = fullname;
	this->salary = salary;
	this->salary_supplement = salary_supplement;
}

std::string EmployeeCompany::getFullName()
{
	return fullname;
}

void EmployeeCompany::setFullName(std::string fullname)
{
	this->fullname = fullname;
}

unsigned int EmployeeCompany::getSalary()
{
	return salary;
}

void EmployeeCompany::setSalary(unsigned int salary)
{
	this->salary = salary;
}

short EmployeeCompany::getSalarySupplement()
{
	return salary_supplement;
}

void EmployeeCompany::setSalarySupplement(short salary_supplement)
{
	this->salary_supplement = salary_supplement;
}

float EmployeeCompany::salaryWithAllowance()
{
	return salary + salary * salary_supplement * 1.f / 100;
}

void EmployeeCompany::printEmployee()
{
	std::cout << "Full name: " << fullname << std::endl;
	std::cout << "Salary: " << salary << std::endl;
	std::cout << "Salary supplement: " << salary_supplement << std::endl;
}

TwoValues readDataDynamic(const std::string& file_path)
{
	std::ifstream readFile(file_path);

	if (!readFile)
	{
		std::cerr << "Failed to open file" << std::endl;
		return TwoValues();
	}

	int quantity;
	readFile >> quantity;

	EmployeeCompany* dataEmployee = new EmployeeCompany[quantity];
	for (size_t i = 0; i < quantity; ++i)
	{
		std::string fullname;
		unsigned int salary;
		short salary_supplement;

		readFile >> fullname >> salary >> salary_supplement;

		dataEmployee[i] = EmployeeCompany(fullname, salary, salary_supplement);
	}

	return TwoValues{ dataEmployee, quantity };
}

std::vector<EmployeeCompany> readDataSTL(const std::string& file_path)
{
	std::ifstream readFile(file_path);

	std::vector<EmployeeCompany> dataEmployee;

	if (!readFile)
	{
		std::cerr << "Failed to open file" << std::endl;
		return dataEmployee;
	}

	int quantity;
	readFile >> quantity;

	dataEmployee.reserve(quantity);
	for (size_t i = 0; i < quantity; ++i)
	{
		std::string fullname;
		unsigned int salary;
		short salary_supplement;

		readFile >> fullname >> salary >> salary_supplement;

		dataEmployee.push_back(EmployeeCompany(fullname, salary, salary_supplement));
	}

	return dataEmployee;
}

void printData(std::vector<EmployeeCompany>& container, const std::string mode)
{
	if (mode == "file")
	{
		std::string outputFileName;
		std::cout << "Enter the name of the output file: ";
		std::cin >> outputFileName;

		std::ofstream outputFile(outputFileName);

		if (!outputFile)
		{
			std::cerr << "Failed to open file" << std::endl;
			return;
		}

		for (size_t i = 0; i < container.size(); ++i)
		{
			outputFile << "Full name: " << container[i].getFullName() << std::endl;
			outputFile << "Salary: " << container[i].getSalary() << std::endl;
			outputFile << "Salary supplement: " << container[i].getSalarySupplement() << std::endl;
			outputFile << "Salary with an allowance: " << container[i].salaryWithAllowance() << std::endl;
			outputFile << "#############################################" << std::endl;
		}

		outputFile.close();
	}
	else
	{
		for (size_t i = 0; i < container.size(); ++i)
		{
			std::cout << "Full name: " << container[i].getFullName() << std::endl;
			std::cout << "Salary: " << container[i].getSalary() << std::endl;
			std::cout << "Salary supplement: " << container[i].getSalarySupplement() << std::endl;
			std::cout << "Salary with an allowance: " << container[i].salaryWithAllowance() << std::endl;
			std::cout << "#############################################" << std::endl;
		}
	}

	std::cout << "Successfully!" << std::endl;
}

void printData(EmployeeCompany* container, const int quantity, const std::string mode)
{
	if (mode == "file")
	{
		std::string outputFileName;
		std::cout << "Enter the name of the output file: ";
		std::cin >> outputFileName;

		std::ofstream outputFile(outputFileName);

		if (!outputFile)
		{
			std::cerr << "Failed to open file" << std::endl;
			return;
		}

		for (size_t i = 0; i < quantity; ++i)
		{
			outputFile << "Full name: " << container[i].getFullName() << std::endl;
			outputFile << "Salary: " << container[i].getSalary() << std::endl;
			outputFile << "Salary supplement: " << container[i].getSalarySupplement() << std::endl;
			outputFile << "Salary with an allowance: " << container[i].salaryWithAllowance() << std::endl;
			outputFile << "#############################################" << std::endl;
		}

		outputFile.close();
	}
	else
	{
		for (size_t i = 0; i < quantity; ++i)
		{
			std::cout << "Full name: " << container[i].getFullName() << std::endl;
			std::cout << "Salary: " << container[i].getSalary() << std::endl;
			std::cout << "Salary supplement: " << container[i].getSalarySupplement() << std::endl;
			std::cout << "Salary with an allowance: " << container[i].salaryWithAllowance() << std::endl;
			std::cout << "#############################################" << std::endl;
		}
	}

	delete[] container;

	std::cout << "Successfully!" << std::endl;
}