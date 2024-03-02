#include "sources.hpp"

Vector::Vector() : data_(nullptr), size_(0) {}

Vector::Vector(const double* array, size_t size) : size_(size)
{
    data_ = new double[size_];
    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] = array[i];
    }
}

Vector::Vector(const Vector& other)
{
    if (this != &other)
    {
        size_ = other.size_;
        data_ = new double[size_];
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }

        std::cout << "The copy constructor is called" << std::endl;
    }
}

Vector::Vector(Vector&& other)
{
    if (this != &other)
    {
        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;

        std::cout << "The move constructor is called" << std::endl;
    }
}

double& Vector::operator[](size_t index)
{
    return data_[index];
}

Vector Vector::operator+(const Vector& other) const
{
    if (size_ != other.size_)
    {
        return Vector();
    }
    Vector result(other);
    for (size_t i = 0; i < size_; ++i)
    {
        result.data_[i] += data_[i];
    }

    return result;
}

Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        delete[] data_;
        size_ = other.size_;
        data_ = new double[size_];

        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    return *this;
}

Vector& Vector::operator=(Vector&& other)
{
    if (this != &other)
    {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }

    return *this;
}

Vector::~Vector()
{
    delete[] data_;
    data_ = nullptr;
}

std::ostream& operator<<(std::ostream& output_stream, const Vector& vector)
{
    for (size_t i = 0; i < vector.size_; ++i)
    {
        output_stream << vector.data_[i] << " ";
    }

    output_stream << std::endl;

    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Vector& vector)
{
    if (typeid(std::cin) == typeid(input_stream))
        std::cout << "Enter lenght of vector: ";
    size_t size_;
    input_stream >> size_;
    double* array = new double[size_];

    for (size_t i = 0; i < size_; ++i)
    {
        input_stream >> array[i];
    }

    vector = Vector(array, size_);
    delete[] array;

    return input_stream;
}

Vector& Vector::operator++()
{
    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] += 1;
    }

    return *this;
}

Vector Vector::operator++(int a)
{
    Vector temp(*this);
    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] += 1;
    }

    return temp;
}
