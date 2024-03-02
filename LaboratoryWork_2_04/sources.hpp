#include <deque>
#include <iostream>
#include <string>
#include <vector>


class Employee
{
    std::string fullname;
    std::string date_employment;
    std::string post;
    size_t salary;

public:
    Employee();

    Employee(std::string, std::string, std::string, size_t);

    Employee(const Employee&);

    Employee(Employee&&);

    Employee& operator = (const Employee&);

    friend std::ostream& operator << (std::ostream&, const Employee&);

};