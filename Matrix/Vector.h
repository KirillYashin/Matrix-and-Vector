#pragma once
#include <iostream>
#include <Exception.h>

template <class T>
class Vector
{
protected:
	T* vector;
	int length;
public:
	Vector(int len = 0);
	Vector(const Vector<T>& V);
	virtual  ~Vector();
	int GetLength() const;
	virtual T& operator[](int pos);
	Vector<T> operator +(const Vector<T>& vec); 
	Vector<T> operator -(const Vector<T>& vec);
	T operator *(Vector<T>& vec);
	Vector<T> operator+(const T& vol);
	Vector<T> operator-(const T& vol); 
	Vector<T> operator*(const T& vol);
	bool operator==(const Vector& vec) const;
	bool operator!=(const Vector& vec) const;
	virtual Vector& operator=(const Vector& vec);
	template <class Type1>
	friend std::istream& operator >> (std::istream& in, Vector<Type1>& vec);
	template <class Type1>
	friend std::ostream& operator << (std::ostream& out, const Vector<Type1>& vec);
};

template <class T>
Vector<T>::Vector(int len)
{
	if (len < 0)
		throw Exception("Length error");
	else
		if (len == 0)
		{
			length = len;
			vector = NULL;
		}
		else
		{
			length = len;
			vector = new T[length];
			for (int i = 0; i < length; i++)
				vector[i] = 0;
		}
}

template <class T>
Vector<T>::Vector(const Vector<T>& V)
{
	length = V.length;
	if (length != 0)
	{
		vector = new T[length];
		for (int i = 0; i < length; i++)
		{
			vector[i] = V.vector[i];
		}
	}
	else
		vector = 0;
}

template <class T>
Vector<T>:: ~Vector()
{
	if (vector != 0)
		delete[]vector;
	vector = 0;
}

template <class T>
int Vector<T> ::GetLength() const
{
	return length;
}

template <class T>
T& Vector<T> ::operator[] (int pos)
{
	if (!(pos >= 0 && pos < length))
		throw Exception("Wrong index");
	else
		return vector[pos];
	
}

template <class T>
Vector<T> Vector<T> :: operator +(const Vector<T>& vec)
{
	if (!(length == vec.length))
		throw Exception("Different lengths");
	else
	{
		Vector<T> res(*this);
		for (int i = 0; i < length; i++)
			res[i] = (*this)[i] + vec.vector[i];
		return res;
	}
}

template <class T>
Vector<T> Vector<T> :: operator -(const Vector<T>& vec)
{
	if (!(length == vec.length))
		throw Exception("Different lengths");
	else
	{
		Vector<T> res(*this);
		for (int i = 0; i < length; i++)
			res[i] = (*this)[i] - vec.vector[i];
		return res;
	}
}

template <class T>
T Vector<T> :: operator *(Vector<T>& vec)
{
	if (!(length == vec.length))
		throw Exception("Different lengths");
	else
	{
		int tmp = 0;
		for (int i = 0; i < length; i++)
			tmp += vector[i] * vec.vector[i];
		return tmp;
	}
}

template <class T>
Vector<T> Vector<T>::operator+(const T& vol)
{
	Vector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] + vol;
	return res;
}

template <class T>
Vector<T> Vector<T>::operator-(const T& vol)
{
	Vector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] - vol;
	return res;
}

template <class T>
Vector<T> Vector<T>::operator*(const T& vol)
{
	Vector<T> res(*this);
	for (int i = 0; i < length; i++)
		res.vector[i] = res.vector[i] * vol;
	return res;
}

template <class T>
bool Vector<T>::operator==(const Vector& vec) const
{
	if (length != vec.length)
		return 0;
	else
		for (int i = 0; i < length; i++)
			if (vector[i] != vec.vector[i])
			{
				return 0;
			}
	return 1;
}

template <class T>
bool Vector<T>::operator!=(const Vector& v) const
{
	return !(*this == v);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& vec)
{
	if (this != &vec)
	{
		delete[] vector;
		length = vec.length;
		vector = new T[length];
		for (int i = 0; i < length; i++)
			vector[i] = vec.vector[i];
	}
	return *this;
}

template <class Type1>
std::istream& operator>>(std::istream& in, Vector<Type1>& vec)
{
	for (int i = 0; i < vec.length; i++)
		in >> vec.vector[i];
	return in;
}

template <class Type1>
std::ostream& operator<<(std::ostream& out, const Vector<Type1>& vec)
{
	for (int i = 0; i < vec.length; i++)
		out << vec.vector[i] << " ";
	return out;
}


