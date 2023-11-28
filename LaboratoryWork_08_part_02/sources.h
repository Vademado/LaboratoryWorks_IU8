#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Employee
{
    std::string full_name;
    std::string date_employment;
    std::string post;
    unsigned int base_salary;
};

std::vector<Employee> readDataEmployees(const std::string& dataFilePath);
bool SortingByFullName(const Employee& empl1, const Employee& empl2);
bool SortingByDateEmployment(const Employee& empl1, const Employee& empl2);
bool SortingByBaseSalary(const Employee& empl1, const Employee& empl2);
void print(const std::vector<Employee>& employersVector);