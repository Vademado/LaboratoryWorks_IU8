#pragma once
#include <fstream>
#include <iostream>
#include <typeinfo>

class Vector
{
    double* data_;
    size_t size_ = 0;

public:
    Vector();

    Vector(const double*, size_t);

    Vector(const Vector&);

    Vector(Vector&&);

    double& operator[](size_t);

    Vector& operator=(const Vector&);

    Vector& operator=(Vector&&);

    Vector operator+(const Vector&) const;

    friend std::ostream& operator<<(std::ostream& output_stream, const Vector& vector);

    friend std::istream& operator>>(std::istream& input_stream, Vector& vector);

    Vector& operator++();

    Vector operator++(int);

    ~Vector();
};