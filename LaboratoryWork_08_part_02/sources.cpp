#include "sources.h"

std::vector<Employee> readDataEmployees(const std::string& dataFilePath)
{
    std::ifstream dataFile(dataFilePath);

    if (!dataFile)
    {
        std::cerr << "Failed to open file" << std::endl;
    }

    std::vector<Employee> vector;
    Employee empl;
    std::string base_salary;
    while (dataFile >> empl.full_name >> empl.date_employment >> empl.post >> base_salary)
    {
        empl.base_salary = (unsigned int)std::stoi(base_salary);

        vector.push_back(empl);
    }

    dataFile.close();

    return vector;
}

bool SortingByFullName(const Employee& empl1, const Employee& empl2)
{
    return empl1.full_name < empl2.full_name;
}

bool SortingByDateEmployment(const Employee& empl1, const Employee& empl2) {
    std::vector<unsigned short int> dateEmploymentEmpl1;
    const char* str = empl1.date_employment.c_str();
    char* token;
    char* context = nullptr;

    token = strtok_s((char *)str, "/", &context);
    while (token != nullptr) {
        dateEmploymentEmpl1.push_back((unsigned short int)std::stoi(token));
        std::cout << token << std::endl;
        token = strtok_s(nullptr, "/", &context);
    }

}

bool SortingByBaseSalary(const Employee& empl1, const Employee& empl2) {
    return empl1.base_salary < empl2.base_salary;
}

void print(const std::vector<Employee>& employersVector)
{
    for (Employee employee : employersVector) {
        std::cout << "Employee's full name: " << employee.full_name << std::endl;
        std::cout << "Date of employment: " << employee.date_employment << std::endl;
        std::cout << "Post: " << employee.post << std::endl;
        std::cout << "Base salary: " << employee.base_salary << std::endl;
        std::cout << "#############################################" << std::endl;
    }
}