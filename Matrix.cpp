#include "Matrix.h"
#include <iomanip>
#include "Array.h"

Matrix::Matrix() :rows(0), cols(0), data(nullptr)
{
}

Matrix::Matrix(int r, int c) :Matrix()
{
	if (r <= 0 || c <= 0)
	{
		return;
	}
	data = new Array[r];
	for (int i = 0; i < r; i++)
	{
		data[i].resize(c);
	}
	rows = r;
	cols = c;
}

Matrix::Matrix(const Matrix& ref):Matrix(ref.rows, ref.cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i].getSet(j) = ref.data[i].getSet(j);
        }
    }
}

Matrix::~Matrix()
{
	delete []data;
	data = nullptr;
	rows = 0;
	cols = 0;
}

int& Matrix::at(int r, int c)
{
	if (r <= 0 || c <= 0 || r > rows || c > cols)
	{	
		cout << "Empty Matrix" << endl;
		exit(0);
	}
	else {
		return data[r - 1].getSet(c - 1);
	}
}

const int& Matrix::at(int r, int c) const
{
	if (r <= 0 || c <= 0 || r > rows || c > cols)
	{
		cout << "Empty Matrix" << endl;
		exit(0);
	}
	else {
		return data[r - 1].getSet(c - 1);
	}
}

void Matrix::display() const
{
	if (rows == 0 || cols == 0)
	{
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << data[i].getSet(j);
		}
		cout << endl;
	}
}

bool Matrix::isIdentity() const
{
	if (rows!=cols)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && data[i].getSet(j) != 1)
				return false;

			if (i != j && data[i].getSet(j) != 0)
				return false;
		}
	}
	return true;
}

bool Matrix::isLowerTriangular() const
{
	if (rows != cols)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = i+1; j < cols; j++)
		{
			if (data[i].getSet(j) != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isUpperTriangular() const
{
	if (rows != cols)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[i].getSet(j) != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isTriangular() const
{
	return (isUpperTriangular() ||  isLowerTriangular());
}

int Matrix::getRows() const {
	return rows;
}

int Matrix::getColumns() const {
	return cols;
}

bool Matrix::isEqual(const Matrix& m2) const
{
	if (rows != m2.rows || cols != m2.cols) {
		return false;
	}
	if ((data == nullptr) || (m2.data == nullptr)) {
		return data == m2.data;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (data[i].getSet(j) != m2.data[i].getSet(j)) {
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::Transpose() const
{
	if (data == nullptr) {
		Matrix empty;
		return empty;
	}
	Matrix trasnpose{ cols,rows };

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			trasnpose.data[j].getSet(i) = data[i].getSet(j);
		}
	}
	return trasnpose;
}

Matrix Matrix::Subtract(const Matrix& b) const {
	if ((data == nullptr&&b.data==nullptr)||rows!=b.rows||cols!=b.cols) {
		Matrix empty;
		return empty;
	}
	if (data==nullptr&&b.data!=nullptr)
	{
		Matrix subtr1{ b.rows,b.cols};
		for (int i = 0; i < b.rows; i++)
		{
			for (int j = 0; j < b.cols; j++)
			{
				subtr1.data[i].getSet(j) = -1*(b.data[i].getSet(j));
			}
		}
		return subtr1;
	}
	if (data != nullptr && b.data == nullptr)
	{
		Matrix subtr1{ rows,cols };
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				subtr1.data[i].getSet(j) = data[i].getSet(j);
			}
		}
		return subtr1;
	}
	Matrix subtr{ rows,cols };
	for (int i = 0; i < b.rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			subtr.data[i].getSet(j) = data[i].getSet(j)-b.data[i].getSet(j);
		}
	}
	return subtr;
}

Matrix Matrix::add(const Matrix& b) const {
	if ((data == nullptr && b.data == nullptr) || rows != b.rows || cols != b.cols) {
		Matrix empty;
		return empty;
	}
	if (data == nullptr && b.data != nullptr)
	{
		Matrix add1{ b.rows,b.cols};
		for (int i = 0; i < b.rows; i++)
		{
			for (int j = 0; j < b.cols; j++)
			{
				add1.data[i].getSet(j) = b.data[i].getSet(j);
			}
		}
		return add1;
	}
	if ( b.data== nullptr && data != nullptr)
	{
		Matrix add1{ rows,cols };
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < b.cols; j++)
			{
				add1.data[i].getSet(j) = data[i].getSet(j);
			}
		}
		return add1;
	}
	Matrix add{ rows,cols };
	for (int i = 0; i < b.rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			add.data[i].getSet(j) = data[i].getSet(j) + b.data[i].getSet(j);
		}
	}
	return add;
}

void Matrix::resize(int newRow, int newCol){
	if (newRow <= 0 || newCol <= 0) {;
		return;
	}

	Array* temp = new Array[newRow];
	for (int i = 0; i < newRow; i++)
	{
		temp[i].resize(newCol);
	}
	if (data!=nullptr)
	{
		for (int i = 0; i < (rows <= newRow ? rows : newRow); i++)
		{
			for (int j = 0; j < (cols <= newCol ? cols : newCol); j++)
			{
				temp[i].getSet(j) = data[i].getSet(j);
			}
		}
		delete[]data;
	}
	data = temp;
	rows = newRow;
	cols = newCol;

}

bool Matrix::isSymmetric()  const{
	if (rows != cols) {
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (data[i].getSet(j) != data[j].getSet(i)) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isSkewSymmetric()  const{
	if (rows != cols) {
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (-data[i].getSet(j) != data[j].getSet(i)) {
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::multiply(const Matrix& b) const {
	if (cols != b.rows) {
		Matrix empty;
		return empty;
	}
	Matrix multiply{ rows,b.cols };
	for (int i = 0; i < multiply.rows; i++)
	{
		for (int j = 0; j < multiply.cols; j++)
		{
			multiply.data[i].getSet(j) = 0;
			for (int k = 0; k < cols; k++)
			{
				multiply.data[i].getSet(j) += data[i].getSet(k) * b.data[k].getSet(j);
			}
		}
	}
	return multiply;
}

int Matrix::trace() const
{
	if (rows != cols) {
		exit(0);
	}
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += data[i].getSet(i);
	}
	return sum;
}

int Matrix::antiTrace() const
{
	if (rows != cols) {
		exit(0);
	}int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += data[i].getSet(cols - 1 - i);
	}
	return sum;
}

Matrix Matrix::slice(int r1, int c1, int r2, int c2) const
{
	if (data==nullptr|| r1<1 || c1 < 1 || r2 > rows || c2>cols || r1 > r2 || c1 > c2)
	{
		Matrix empty;
		return empty;
	}
	Matrix sliceMatrix{ (r2 - r1) + 1,(c2 - c1) + 1 };
	int x = 0;
	for (int i = r1 - 1; i < r2; i++)
	{
		int y = 0;
		for (int j = c1 - 1; j < c2; j++)
		{
			sliceMatrix.data[x].getSet(y) = data[i].getSet(j);
			y++;
		}
		x++;
	}return sliceMatrix;
}

Matrix Matrix::minor(int rNo, int cNo) const{
	if (rNo<1 || rNo>rows || cNo<1 || cNo>cols)
	{
		Matrix empty;
		return empty;
	}
	Matrix minorMatrix{ rows - 1,cols - 1 };
	int x = 0;
	for (int i = 0; i < rows; i++)
	{
		if (i != (rNo - 1)) {
			int y = 0;
			for (int j = 0; j < cols; j++)
			{
				if (j != (cNo - 1))
				{
					minorMatrix.data[x].getSet(y) = data[i].getSet(j);
					y++;
				}
			}
			x++;
		}
	}
	return minorMatrix;
}