#pragma once
#include <iostream>
#include <math.h>

class VectorOnPlane
{
protected:
    int x, y;

public:
    VectorOnPlane();

    VectorOnPlane(int, int);

    virtual double length() const;

    virtual std::ostream& printDetails(std::ostream&) const;
};

class VectorInSpace : public VectorOnPlane
{
protected:
    int z;

public:
    VectorInSpace();

    VectorInSpace(int, int, int);

    double length() const override;

    std::ostream& printDetails(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const VectorOnPlane&);