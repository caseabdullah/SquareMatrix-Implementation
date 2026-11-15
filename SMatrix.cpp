#include "SMatrix.h"

SMatrix::SMatrix(int i):order(i),mat(order,order)
{}

SMatrix::SMatrix(const SMatrix& m):order(m.order),mat(m.mat)
{}

SMatrix::SMatrix(const Matrix & m):SMatrix()
{
	if (m.getRows() == 0 || m.getColumns() == 0 || m.getColumns() != m.getRows()) {
		return;
	}
	mat.resize(m.getRows(), m.getColumns());
	order = m.getRows();
	for (int i = 0; i < m.getRows(); i++)
	{
		for (int j = 0; j < m.getColumns(); j++)
		{
			mat.at(i, j) = m.at(i, j);
		}
	}


}

SMatrix::~SMatrix()
{
	order = 0;
}

int& SMatrix::at(int r, int c)
{
	return mat.at(r, c);
}

const int& SMatrix::at(int r, int c) const
{
	return mat.at(r, c);
}

int SMatrix::getOrder() const
{
	return order;
}

void SMatrix::display() const
{
	mat.display();
}

SMatrix SMatrix::Transpose() const
{
	return mat.Transpose();
}

SMatrix SMatrix::add(const SMatrix& b) const
{
	return mat.add(b.mat);
}

SMatrix SMatrix::multiply(const SMatrix& m) const
{
	return mat.multiply(m.mat);
}

SMatrix SMatrix::subtract(const SMatrix& b) const
{
	return mat.Subtract(b.mat);
}

int SMatrix::trace() const
{
	return mat.trace();
}

int SMatrix::antiTrace() const
{
	return mat.antiTrace();
}

bool SMatrix::isSymmetric() const
{
	return mat.isSymmetric();
}

bool SMatrix::isSkewSymmetric() const
{
	return mat.isSkewSymmetric();
}

bool SMatrix::isEqual(const SMatrix& m2) const
{
	return mat.isEqual(m2.mat);
}

bool SMatrix::isIdentity() const
{
	return mat.isIdentity();
}

bool SMatrix::isLowerTriangular() const
{
	return mat.isLowerTriangular();
}

bool SMatrix::isUpperTriangular() const
{
	return mat.isUpperTriangular();
}

bool SMatrix::isTriangular() const
{
	return mat.isTriangular();
}

SMatrix SMatrix:: minor(int rNo, int cNo) const {
	return mat.minor(rNo,cNo);
}

SMatrix SMatrix::slice(int r1, int c1, int r2, int c2) const
{
	Matrix temp = mat.slice(r1, c1, r2, c2);

	if (temp.getRows() == 0 ||
		temp.getColumns() == 0 ||
		temp.getRows() != temp.getColumns())
	{
		return SMatrix();
	}

	return SMatrix{ temp };
}