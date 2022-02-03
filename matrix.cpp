#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

//проверка введеного натурального числа
void correct_input_N(int& num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите натуральное значение переменной!\n";
		cin >> num;
	}
}

//проверка введеного действительного числа
void correct_input_R(double& num) {
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите вещественное значение переменной!\n";
		cin >> num;
	}
}


//создание нулевой квадратной матрицы
double** matrix_nul_create(int n) {
	double** out_matr = new double* [n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

//ввод начальной квадратной матрицы
double** matrix_input(int n) {
	double** orig_matr = matrix_nul_create(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			correct_input_R(element);
			orig_matr[i][j] = element;
		}
	return orig_matr;
}

//вывод начальной квадратной матрицы
void matrix_output(double** orig_matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//функция сложения квадратной матрицы с числом
double** matrix_addition_num(double** matr, int n, int num) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				out_matr[i][j] = num + matr[i][j];
			else
				out_matr[i][j] = matr[i][j];
		}
	return out_matr;
}

//функция умножения квадратной матрицы на число
double** matrix_multiply_num(double** matr, int n, int num) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//функция сложения квадратных матриц
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//функция перемножения квадратных матриц
double** matrix_multiply_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}
