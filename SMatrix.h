#ifndef SMATRIX_X
#define SMATRIX_X

#include "Matrix.h"
class SMatrix
{
    Matrix mat;
    int order;
    SMatrix(const Matrix&);
public:
    SMatrix(int i=0);
    SMatrix(const SMatrix&);
    ~SMatrix();
    int& at(int, int);
    const int& at(int, int) const;
    int getOrder() const;
    void display() const;
    SMatrix Transpose() const;
    SMatrix add(const SMatrix&) const;
    SMatrix multiply(const SMatrix&) const;
    SMatrix subtract(const SMatrix&) const;
    int trace() const;
    int antiTrace() const;
    bool isSymmetric() const;
    bool isSkewSymmetric() const;
    bool isEqual(const SMatrix& m2) const;
    bool isIdentity() const;
    bool isLowerTriangular() const;
    bool isUpperTriangular() const;
    bool isTriangular() const;
    SMatrix slice(int r1, int c1, int r2, int c2) const;
    SMatrix minor(int rNo, int cNo) const;
};

#endif