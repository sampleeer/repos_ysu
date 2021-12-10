/*
 * Лабороторная работа №6
 * Описание: дана матрица и функция 
 нужно найти значение матрицы от функции x^4  + 5 * x^2 + 3 в квадрате
 * Автор: Нехаенко Павел Александрович
 * Название класса и учебной группы: пми-13 бо
 * Дата релиза: 8.12.2021
 */
#include  <iostream>
#include "functions.h"
#include <windows.h>
#include <math.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	int** matrix;
	cout << "Введите размерность матрицы:" << '\n';
	n = check_dimension();
	int** matrix2;// Создаем матрицу введенной размерности
	matrix2 = new int*[n]; // через массив указателей
	cout << "Введите матрицу" << '\n';
	matrix = create(n);
	cout << "матрица, с примененной формулой = " << '\n';
	changed_matrix(matrix, n);
	system("pause");
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix; // Освобождение памяти
	return 0;
}