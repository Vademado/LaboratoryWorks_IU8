#include "sources.hpp"

EmployeeCompany::EmployeeCompany()
{
	this->fullname = "";
	this->salary = 0;
	this->salary_supplement = 0;
}

EmployeeCompany::EmployeeCompany(std::string fullname, unsigned int salary, short salary_supplement)
{
	this->fullname = fullname;
	this->salary = salary;
	this->salary_supplement = salary_supplement;
}

std::string EmployeeCompany::getFullName()
{
	return fullname;
}

void EmployeeCompany::setFullName(std::string fullname)
{
	this->fullname = fullname;
}

unsigned int EmployeeCompany::getSalary()
{
	return salary;
}

void EmployeeCompany::setSalary(unsigned int salary)
{
	this->salary = salary;
}

short EmployeeCompany::getSalarySupplement()
{
	return salary_supplement;
}

void EmployeeCompany::setSalarySupplement(short salary_supplement)
{
	this->salary_supplement = salary_supplement;
}

float EmployeeCompany::salaryWithAllowance()
{
	return salary + salary * salary_supplement * 1.f / 100;
}

void EmployeeCompany::printEmployee()
{
	std::cout << "Full name: " << fullname << std::endl;
	std::cout << "Salary: " << salary << std::endl;
	std::cout << "Salary supplement: " << salary_supplement << std::endl;
}


template<typename T>
MyUnique<T>::MyUnique(T* ptr) : value_ptr(ptr) {}

template<typename T>
T* MyUnique<T>::get() const 
{
	return value_ptr;
}

template<typename T>
T& MyUnique<T>::operator*()
{
	return *value_ptr;
}

template<typename T>
T* MyUnique<T>::operator->()
{
	return value_ptr;
}

template<typename T>
MyUnique<T>::MyUnique(MyUnique<T>&& other)
{
	value_ptr = other.value_ptr;
	other.value_ptr = nullptr;
}

template<typename T>
MyUnique<T>& MyUnique<T>::operator=(MyUnique<T>&& other)
{
	if (this != &other)
	{
		value_ptr = other.value_ptr;
		other.value_ptr = nullptr;
	}
}

template<typename T>
MyUnique<T>::~MyUnique()
{
	delete value_ptr;
}

template<typename T, typename ...Args>
MyUnique<T> Make_MyUnique(Args&&... args)
{
	T* ptr = new T(std::forward<Args>(args)...);
	return MyUnique<T>(ptr);
}

// Make_MyUnique<Myclass>(....) 