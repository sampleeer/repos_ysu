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
	cout << "Введите размерность матрицы:" << '\n';
	n = input_check_dimension();
	cout << "Введите матрицу" << '\n';
	double** matrix = create_matrix(n);// Создаем матрицу введенной размерности
	double** matrix_result = create_null_matrix(n);// Создаем вторую матрицу введенной размерности для использования функции
	cout << "матрица, с примененной формулой = " << '\n';
	changed_matrix(matrix, n, matrix_result);
	memory_clear_matrix(matrix, n);
	memory_clear_matrix(matrix_result, n);
	system("pause");
	return 0;
}