#pragma once
#include <iostream>
#include <utility>

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

template<typename T>
class MyUnique 
{
private:
	T* value_ptr = nullptr;

public:
	MyUnique(T*);

	T* get() const;

	T& operator*();

	T* operator->();

	MyUnique(const MyUnique<T>&) = delete;

	MyUnique& operator=(const MyUnique<T>&) = delete;

	MyUnique(MyUnique<T>&&);

	MyUnique& operator=(MyUnique<T>&&);

	~MyUnique();
};

template<typename T, typename ...Args>
MyUnique<T> Make_MyUnique(Args&&... args);