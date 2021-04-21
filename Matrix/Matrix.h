#pragma once
#include "Vector.h"
#include <iomanip>

template <class T>
class Matrix : public Vector<Vector<T>>
{
public:
	Matrix(int len = 10);
	Matrix(const Matrix& matr);
	Matrix(const Vector<Vector<T> >& matr);
	virtual ~Matrix();
	Matrix operator+(const Matrix& matr);
	Matrix operator-(const Matrix& matr);
	Matrix<T> operator*(const Matrix<T>& matr);
	Matrix<T> operator/(const Matrix<T>& matr);
	bool operator==(const Matrix& matr) const;
	bool operator!=(const Matrix& matr) const;
	Matrix& operator=(const Matrix& matr);
	template <class Type2>
	friend std::istream& operator>>(std::istream& in, Matrix<Type2>& matr);
	template <class Type2>
	friend std::ostream& operator<<(std::ostream& out, const Matrix<Type2>& matr);
};

template <class T>
Matrix<T>::Matrix(int len) :Vector<Vector<T> >(len)
{
	if (len <= 0 || len > 1000)
		throw Exception("Length error");
	for (int i = 0; i < len; i++)
		this->vector[i] = Vector<T>(len - i);
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& matr) :Vector<Vector<T>>(matr) {}

template <class T>
Matrix<T>::Matrix(const Vector<Vector<T> >& matr) : Vector<Vector<T>>(matr) {}

template <class T>
Matrix<T>::~Matrix() {}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& matr)
{
	if (this->length == matr.length)
		return Vector<Vector<T> >::operator+(matr);
	else
		throw Exception("Different lengths");
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matr)
{
	if (this->length == matr.length)
		return Vector<Vector<T> >::operator-(matr);
	else
		throw Exception("Different lengths");
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matr)
{
	if (this->length != matr.length)
		throw Exception("Different lengths");
	Matrix <T> res(this->length);
	for (int i = 0; i < this->length; i++)
		for (int j = i; j < this->length; j++) {
			for (int k = i; k <= j; k++)
				res.vector[i][j - i] += this->vector[i][k - i] * matr.vector[k][j - k];
		}
	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& matr)
{
	if (this->length != matr.length)
		throw Exception("Different lengths");
	Matrix <T> copy(*this);
	Matrix <T> res(this->length);
	Matrix <T> copyMt(matr);

	for (int i = 0; i < this->length; i++)
		res[i][0] = 1 / copyMt[i][0];

	for (int i = 0; i < this->length - 1; i++)
		for (int j = 1; j < this->length - i; j++)
		{
			if (copyMt[i][j] != 0)
			{
				T temp = copyMt[i][j];
				res[i][j] = (-1) * copyMt[i][j] * res[i + j][0];
				for (int k = j, l = 0; k < this->length - i; k++)
					copyMt[i][k] = copyMt[i][k] - copyMt[j][l++] * temp;
			}
		}
	res = copy * res;
	return res;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& matr) const
{
	return Vector<Vector<T>>::operator == (matr);
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& matr) const
{
	return Vector<Vector<T>>::operator!=(matr);
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matr)
{
	Vector<Vector<T>>::operator = (matr);
	return *this;
}

template <class Type2>
std::istream& operator>>(std::istream& in, Matrix<Type2>& matr)
{
	for (int i = 0; i < matr.length; i++)
		in >> matr.vector[i];
	return in;
}

template <class Type2>
std::ostream& operator<<(std::ostream& out, const Matrix<Type2>& matr)
{
	for (int i = 0; i < matr.length; i++)
	{
		for (int k = 0; k < i; k++)
			out << "  ";
		out << std::setprecision(3) << matr.vector[i] << std::endl;
	}
	return out;
}

