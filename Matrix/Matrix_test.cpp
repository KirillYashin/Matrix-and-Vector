#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <locale>
#include <cstdlib>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Векторы" << std::endl << std::endl;
	Vector <int> V1(3), V2(3), Res(3);
	for (int i = 0; i < 3; i++)
	{
		V1[i] = std::rand() % 100;
		V2[i] = std::rand() % 100;
	}
	std::cout << "Вектор 1: " << V1 << std::endl;
	std::cout << "Вектор 2: " << V2 << std::endl << std::endl;

	std::cout << "Результаты арифмитеческих операций:" << std::endl << std::endl;
	try
	{
		Res = V1 + 3;
		std::cout << "Вектор 1 + число 3: " << Res << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try
	{
		Res = V1 - 2;
		std::cout << "Вектор 1 - число 2: " << Res << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try
	{
		Res = V1 * 4;
		std::cout << "Вектор 1 * число 4: " << Res << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try
	{
		Res = V1 + V2;
		std::cout << "Вектор 1 + Вектор 2: " << Res << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try
	{
		Res = V1 - V2;
		std::cout << "Вектор 1 - Вектор 2: " << Res << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try
	{
		int k = V1 * V2;
		std::cout << "Вектор 1 * Вектор 2: " << k << std::endl << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	std::cout << "Проверим правильность работы операции ввода и вывода" << std::endl;
	std::cout << "Введите вектор, размерности 5:" << std::endl;
	Vector <int> V(5);
	std::cin >> V;
	std::cout << "Введенный вами вектор: " << V << std::endl << std::endl;

	std::cout << "Матрицы" << std::endl << std::endl;
	Matrix<double> M1(5), M2(5), MRes(5);
	Matrix<double> MDel(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			M1[i][j] = std::rand() % 10;
			M2[i][j] = std::rand() % 10;
		}
	std::cout << "Матрица 1:" << std::endl << M1 << std::endl;
	std::cout << "Матрица 2:" << std::endl << M2 << std::endl << std::endl;

	std::cout << "Арифметические операции:" << std::endl << std::endl;
	try {
		MRes = M1 + M2;
		std::cout << "Матрица 1 + Матрица 2:" << std::endl << MRes << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try {
		MRes = M1 - M2;
		std::cout << "Матрица 1 - Матрица 2:" << std::endl << MRes << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try {
		MRes = M1 * M2;
		std::cout << "Матрица 1 * Матрица 2:" << std::endl << MRes << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	try {
		MDel = M1 / M2;
		std::cout << "Матрица 1 / Матрица 2:" << std::endl << MDel << std::endl;
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	std::cout << "Проверим правильность работы операции ввода и вывода" << std::endl;
	std::cout << "Введите матрицу размерности 3:" << std::endl;
	Matrix <int> MT(3);
	std::cin >> MT;
	std::cout << "Введенная вами матрица:" << std::endl << MT;
	std::cout << "Проверим правильность работы исключений" << std::endl;
	try {
		std::cout << "Введите 0, если хотите проверить исключение для конструктора вектора" << std::endl;
		std::cout << "Введите 1, если хотите проверить исключение для оператора [] у вектора" << std::endl;
		std::cout << "Введите 2, если хотите проверить исключение для оператора сложения у вектора" << std::endl;
		std::cout << "Введите 3, если хотите проверить исключение для оператора сложения у матриц" << std::endl;
		int mode;
		std::cin >> mode;
		Vector <int> test1(1), test2(2);
		Matrix <int> test3(1), test4(2);
		switch (mode)
		{
		case 1:
			std::cout << "Обращаемся к элементу с индексом -1 - получаем ошибку" << std::endl << std::endl;
			std::cout << test1[-1];
			break;
		case 2:
			std::cout << "Складываем 2 вектора разной длины - получаем ошибку" << std::endl;
			std::cout << "Исключение для умножения и вычитания работают аналогично" << std::endl << std::endl;
			test1 + test2;
		case 3:
			std::cout << "Складываем 2 матрицы разных размерностей - получаем ошибку" << std::endl;
			std::cout << "Исключение для умножения, вычитания и деления работают аналогично" << std::endl << std::endl;
			test3 + test4;
		default:
			std::cout << "Создаем вектор отрицательной длины - получаем ошибку" << std::endl;
			std::cout << "Исключение для матриц работает аналогично" << std::endl << std::endl;
		}
		Vector <int> temp(-1);
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}
