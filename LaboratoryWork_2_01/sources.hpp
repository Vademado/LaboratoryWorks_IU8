#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class EmployeeCompany
{
    std::string fullname;
    unsigned int salary;
    short salary_supplement;

public:
    EmployeeCompany();

    explicit EmployeeCompany(std::string, unsigned int, short);

    std::string getFullName();

    void setFullName(std::string);

    unsigned int getSalary();

    void setSalary(unsigned int);

    short getSalarySupplement();

    void setSalarySupplement(short);

    float salaryWithAllowance();

    void printEmployee();
};

struct TwoValues
{
    EmployeeCompany* dataEmployee;
    int quantity = 0;
};

TwoValues readDataDynamic(const std::string&);

std::vector<EmployeeCompany> readDataSTL(const std::string&);

void printData(std::vector<EmployeeCompany>&, const std::string);

void printData(EmployeeCompany*, const int, const std::string);
