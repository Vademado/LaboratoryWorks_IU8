#pragma once
#include <algorithm>
#include <deque>
#include <fstream>
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

    bool operator<(const Employee&) const;

    bool operator()(const Employee&, const Employee&) const;

    std::string getName() const;

    friend std::ostream& operator << (std::ostream&, const Employee&);

    friend std::istream& operator >> (std::istream&, Employee&);
};

std::vector<Employee> readData(std::istream&);

bool sortingByName(const Employee&, const Employee&);
