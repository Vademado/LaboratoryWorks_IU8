#include "sources.hpp"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");

    if (argc < 4)
    {
        std::cout << "Error: Insufficient command line arguments" << std::endl;
        return 1;
    }

    std::string file_path = argv[1], container_type = argv[2], mode = argv[3];

    if (container_type == "stl")
    {
        std::vector<EmployeeCompany> dataEmployee = readDataSTL(file_path);
        printData(dataEmployee, mode);
    }
    else
    {
        TwoValues readData = readDataDynamic(file_path);
        printData(readData.dataEmployee, readData.quantity, mode);
    }

    return 0;
}