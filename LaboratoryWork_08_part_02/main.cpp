#include "sources.h"

int main() {

	char str[] = "apple,orange,banana";
	char* token;
	char* context = nullptr;

	token = strtok_s(str, ",", &context);
	while (token != nullptr) {
		std::cout << token << std::endl;
		token = strtok_s(nullptr, ",", &context);
	}

	std::vector<Employee> employersVector = readDataEmployees("EmpoyeesData.txt");

	std::sort(employersVector.begin(), employersVector.end(), SortingByFullName);
	print(employersVector);

	return 0;
}