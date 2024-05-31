#pragma once
#include <iostream>
#include <utility>

class MyPoint
{
private:
	int x, y, z;

public:
	MyPoint()
	{
		x = y = z = 0;
	}

	MyPoint(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int get_x() const
	{
		return x;
	}

	int get_y() const
	{
		return y;
	}

	int get_z() const
	{
		return z;
	}

	void set_x(int x)
	{
		this->x = x;
	}

	void set_y(int y)
	{
		this->y = y;
	}

	void set_z(int z)
	{
		this->z = z;
	}

	std::ostream& print(std::ostream& output_stream) const
	{
		output_stream << "point coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;

		return output_stream;
	}

};

template<typename T>
class MyUnique 
{
private:
	T* value_ptr = nullptr;

public:
	MyUnique(T* ptr)
	{
		value_ptr = ptr;
	}


	T* get() const
	{
		return value_ptr;
	}

	T& operator*()
	{
		return *value_ptr;
	}

	T* operator->()
	{
		return value_ptr;
	}

	MyUnique(const MyUnique<T>&) = delete;

	MyUnique& operator=(const MyUnique<T>&) = delete;

	MyUnique(MyUnique<T>&& other)
	{
		value_ptr = other.value_ptr;
		other.value_ptr = nullptr;
	}

	MyUnique& operator=(MyUnique<T>&& other)
	{
		if (this != &other)
		{
			value_ptr = other.value_ptr;
			other.value_ptr = nullptr;
		}

		return *this;
	}

	~MyUnique()
	{
		delete value_ptr;
	}
};

class Manager 
{
private:
	int use_count;

public:
	Manager() 
	{
		use_count = 1;
	}

	int get() 
	{
		return use_count;
	}

	void add_ptr() 
	{
		++use_count;
	}

	void del_ptr() 
	{
		--use_count;
	}
};

template<typename T>
class MyShared
{
private:
	T* value_ptr = nullptr;
	Manager* manager;

public:

	MyShared(T* ptr)
	{
		value_ptr = ptr;
		manager = new Manager;
	}

	T* get() const
	{
		return value_ptr;
	}

	T& operator*()
	{
		return *value_ptr;
	}

	T* operator->()
	{
		return value_ptr;
	}

	void count_use_pointers() 
	{
		std::cout << manager->get() << std::endl;
	}

	MyShared(MyShared<T>& other)
	{
		value_ptr = other.value_ptr;
		manager = other.manager;
		manager->add_ptr();
	}

	MyShared& operator=(MyShared<T>& other)
	{
		if (this != &other) 
		{
			manager->del_ptr();
			value_ptr = other.value_ptr;
			manager = other.manager;
			manager->add_ptr();
		}
		return *this;
	}

	MyShared(MyShared<T>&& other)
	{
		value_ptr = other.value_ptr;
		other.value_ptr = nullptr;
		manager = other.manager;
		other.manager = nullptr;
	}

	MyShared& operator=(MyShared<T>&& other)
	{
		if (this != &other)
		{
			value_ptr = other.value_ptr;
			other.value_ptr = nullptr;
			manager = other.manager;
			other.manager = nullptr;
		}
		return *this;
	}

	~MyShared()
	{
		std::cout << "Destructor is called  " << "use_pointers=" << manager->get() << std::endl;
		if (value_ptr && manager->get() == 1) 
		{
			delete value_ptr;
			delete manager;
			std::cout << "__memory is freed__" << std::endl;
		}
		else
		{
			manager->del_ptr();
		}
	}
};

template<typename T, typename ...Args>
MyUnique<T> Make_MyUnique(Args&&... args)
{
	T* ptr = new T(std::forward<Args>(args)...);
	return MyUnique<T>(ptr);
}

template<typename T, typename ...Args>
MyShared<T> Make_MyShared(Args&&... args)
{
	T* ptr = new T(std::forward<Args>(args)...);
	return MyShared<T>(ptr);
}

std::ostream& operator<<(std::ostream& output_stream, const MyPoint& point)
{
	return point.print(output_stream);
}