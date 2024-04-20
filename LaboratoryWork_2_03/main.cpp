#include "sources.hpp"

int main()
{

    VectorOnPlane xy;
    VectorInSpace xyz(1, 2, 3);

    std::cout << xy;
    std::cout << xyz;

    VectorOnPlane* vec1 = new VectorOnPlane(1, 3);
    VectorOnPlane* vec2 = new VectorInSpace(0, 7, 8);

    std::cout << vec1->length() << std::endl;
    std::cout << vec2->length();

    return 0;
}