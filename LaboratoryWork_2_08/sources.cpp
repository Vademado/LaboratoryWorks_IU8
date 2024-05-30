//#include "sources.hpp"
//
//
//MyPoint::MyPoint() : x(0), y(0), z(0) {};
//
//MyPoint::MyPoint(int x, int y, int z) : x(x), y(y), z(z) {};
//
//int MyPoint::get_x() const
//{
//	return x;
//}
//
//int MyPoint::get_y() const
//{
//	return y;
//}
//
//int MyPoint::get_z() const
//{
//	return z;
//}
//
//void MyPoint::set_x(int x)
//{
//	this->x = x;
//}
//
//void MyPoint::set_y(int y)
//{
//	this->y = y;
//}
//
//void MyPoint::set_z(int z)
//{
//	this->z = z;
//}
//
//template<typename T>
//MyUnique<T>::MyUnique(T* ptr) 
//{
//	value_ptr = ptr;
//}
//
//template<typename T>
//T* MyUnique<T>::get() const 
//{
//	return value_ptr;
//}
//
//template<typename T>
//T& MyUnique<T>::operator*()
//{
//	return *value_ptr;
//}
//
//template<typename T>
//T* MyUnique<T>::operator->()
//{
//	return value_ptr;
//}
//
//template<typename T>
//MyUnique<T>::MyUnique(MyUnique<T>&& other)
//{
//	value_ptr = other.value_ptr;
//	other.value_ptr = nullptr;
//}
//
//template<typename T>
//MyUnique<T>& MyUnique<T>::operator=(MyUnique<T>&& other)
//{
//	if (this != &other)
//	{
//		value_ptr = other.value_ptr;
//		other.value_ptr = nullptr;
//	}
//
//	return *this;
//}
//
//template<typename T>
//MyUnique<T>::~MyUnique()
//{
//	delete value_ptr;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//template<typename T>
//int MyShared<T>::count = 0;
//
//template<typename T>
//MyShared<T>::MyShared(T* ptr)
//{
//	value_ptr = ptr;
//	++count;
//}
//
//template<typename T>
//MyShared<T>::~MyShared()
//{
//	if (count) 
//	{
//		value_ptr = nullptr;
//	}
//
//	delete value_ptr;
//}

//template<typename T, typename ...Args>
//MyUnique<T> Make_MyUnique(Args&&... args)
//{
//	T* ptr = new T(std::forward<Args>(args)...);
//	return MyUnique<T>(ptr);
//}

//int sum(T1 a, T2 b) {
//
//}
//
//summ(1, 3);

// Make_MyUnique<Myclass>(....) 