#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class Employee
{
private:
    std::string fullname;
    std::string date_employment;
    std::string post;
    size_t salary;

public:
    Employee();

    Employee(std::string, std::string, std::string, size_t);

    Employee(const Employee&);

    Employee(Employee&&) noexcept;

    Employee& operator = (const Employee&);

    Employee& operator = (Employee&&) noexcept;

    bool operator == (const Employee&) const; // для контейнеров set и map

    bool operator<(const Employee&) const; // для контейнеров set и map

    bool operator()(const Employee&, const Employee&) const;

    std::string getName() const;

    friend std::ostream& operator << (std::ostream&, const Employee&);

    friend std::istream& operator >> (std::istream&, Employee&);
};

std::vector<Employee> readData(std::istream&);

bool sortingByName(const Employee&, const Employee&);