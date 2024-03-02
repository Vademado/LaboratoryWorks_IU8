#include "sources.hpp"

VectorOnPlane::VectorOnPlane() : x(0), y(0) { std::cout << "VectorOnPlane constructor" << std::endl; };

VectorOnPlane::VectorOnPlane(int x, int y) : x(x), y(y) {};

double VectorOnPlane::length() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

std::ostream& VectorOnPlane::printDetails(std::ostream& output_stream) const
{
    output_stream << "vector coordinates: (" << x << ", " << y << ")" << std::endl;
    output_stream << "vector length: " << length() << std::endl;
    output_stream << "###################################" << std::endl;

    return output_stream;
}

VectorInSpace::VectorInSpace() : VectorOnPlane(), z(0) { std::cout << "VectorInSpace constructor" << std::endl; };

VectorInSpace::VectorInSpace(int x, int y, int z) : VectorOnPlane(x, y), z(z) {};

double VectorInSpace::length() const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

std::ostream& VectorInSpace::printDetails(std::ostream& output_stream) const
{
    output_stream << "vector coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
    output_stream << "vector length: " << length() << std::endl;
    output_stream << "###################################" << std::endl;

    return output_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const VectorOnPlane& vector)
{
    return vector.printDetails(output_stream);
}