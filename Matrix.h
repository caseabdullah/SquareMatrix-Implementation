#ifndef MATRIX_H
#define MATRIX_H
class Array;

class Matrix {
    Array* data;
    int cols;
    int rows;
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix& ref);
    ~Matrix();
    int& at(int r, int c);
    const int& at(int r, int c) const;
    void display() const;
    bool isIdentity() const;
    bool isLowerTriangular() const;
    bool isUpperTriangular() const;
    bool isTriangular() const;
    int getRows() const;
    int getColumns() const;
    bool isEqual(const Matrix& m2) const;
    Matrix Transpose()  const;
    Matrix Subtract(const Matrix& b) const;
    Matrix add(const Matrix& b) const;
    void resize(int newRow, int newCol);
    bool isSymmetric() const;
    bool isSkewSymmetric() const;
    Matrix multiply(Matrix& b) const;
    int trace() const;
    int antiTrace() const;
    Matrix slice(int r1, int c1, int r2, int c2) const;
    Matrix minor(int rNo, int cNo) const;
};

#endif