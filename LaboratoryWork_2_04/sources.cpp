#include "sources.hpp"

Employee::Employee() : fullname(""), date_employment(""), post(""), salary(0) {}

Employee::Employee(std::string fullname, std::string date_employment, std::string post, size_t salary) : fullname(fullname), date_employment(date_employment), post(post), salary(salary) {}

Employee::Employee(const Employee& other) : fullname(other.fullname), date_employment(other.date_employment), post(other.post), salary(other.salary) {}

Employee::Employee(Employee&& other) : fullname(other.fullname), date_employment(other.date_employment), post(other.post), salary(other.salary)
{
	other.fullname = "";
	other.date_employment = "";
	other.post = "";
	other.salary = 0;
}

Employee& Employee::operator=(const Employee& other) : fullname(other.fullname), date_employment(other.date_employment), post(other.post), salary(other.salary)
{
	return *this;
}
;

std::ostream& operator<<(std::ostream& output_stream, const Employee& employeer)
{
	output_stream << "Fullname: " << employeer.fullname << std::endl;
	output_stream << "Date of employment: " << employeer.date_employment << std::endl;
	output_stream << "Post: " << employeer.post << std::endl;
	output_stream << "Salary: " << employeer.salary << std::endl;
	output_stream << "#########################################" << std::endl;
}
