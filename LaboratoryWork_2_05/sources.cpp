#include "sources.hpp"

Employee::Employee() : fullname(""), date_employment(""), post(""), salary(0) {}

Employee::Employee(std::string fullname, std::string date_employment, std::string post, size_t salary) : fullname(fullname), date_employment(date_employment), post(post), salary(salary) {}

Employee::Employee(const Employee& other) : fullname(other.fullname), date_employment(other.date_employment), post(other.post), salary(other.salary) {}

Employee::Employee(Employee&& other) noexcept : fullname(other.fullname), date_employment(other.date_employment), post(other.post), salary(other.salary)
{
	other.fullname = "";
	other.date_employment = "";
	other.post = "";
	other.salary = 0;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) {
		fullname = other.fullname;
		date_employment = other.date_employment;
		post = other.post;
		salary = other.salary;
	}

	return *this;
}

Employee& Employee::operator=(Employee&& other) noexcept
{
	if (this != &other) {
		fullname = other.fullname;
		date_employment = other.date_employment;
		post = other.post;
		salary = other.salary;

		other.fullname = "";
		other.date_employment = "";
		other.post = "";
		other.salary = 0;
	}

	return *this;
}

bool Employee::operator==(const Employee& other) const
{
	return fullname == other.fullname;
}

bool Employee::operator<(const Employee& other) const
{
	return fullname < other.fullname;
}

bool Employee::operator()(const Employee& firstEmployee, const Employee& secondEmployee) const
{
	return firstEmployee < secondEmployee;
}

std::string Employee::getName() const
{
	return fullname;
}

std::ostream& operator<<(std::ostream& output_stream, const Employee& employeer)
{
	output_stream << "Fullname: " << employeer.fullname << std::endl;
	output_stream << "Date of employment: " << employeer.date_employment << std::endl;
	output_stream << "Post: " << employeer.post << std::endl;
	output_stream << "Salary: " << employeer.salary << std::endl;
	output_stream << "#########################################" << std::endl;

	return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Employee& employeer)
{
	input_stream >> employeer.fullname;
	input_stream >> employeer.date_employment;
	input_stream >> employeer.post;
	input_stream >> employeer.salary;

	return input_stream;
}

std::vector<Employee> readData(std::istream& input_stream)
{
	size_t n;
	input_stream >> n;
	std::vector<Employee> deque_emloyee(n);
	for (size_t i = 0; i < n; ++i)
	{
		input_stream >> deque_emloyee[i];
	}
	return deque_emloyee;
}

bool sortingByName(const Employee& firstEmployee, const Employee& secondEmployee)
{
	return firstEmployee.getName() < secondEmployee.getName();
}

namespace std {

	template<>
	struct hash<Employee> {
		size_t operator()(const Employee& employee) const {
			return hash<string>()(employee.getName());
		}

	};
}