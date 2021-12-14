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
	while (cin.fail() ) {
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
			cout << orig_matr[i][j];
		cout << endl;
	}
}

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr) {
	int row_shift = 0; //Смещение индекса строки в матрице
	int col_shift = 0; //Смещение индекса столбца в матрице
	for (int i = 0; i < n - 1; i++) {
		//Пропустить row-ую строку
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < n - 1; j++) {
			//Пропустить col-ый столбец
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//Рекурсивная функция для нахождения определителя матрицы. 
int matrix_det(double** matr, int n) {
	//временная матрица, полученная вычеркиванием i-ой строки и 0-ого столбца
	double** temp = matrix_nul_create(n - 1);
	double det = 0;
	double alg_dop = 0;
	//если дошли до минора 2х2, то возвращаекм его
	if (n == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//условие выхода из рекурсии
	if (n == 1) {
		return matr[0][0];
	}
	//знак для высчитывания алгебраического дополнения
	int sign = 1;
	for (int i = 0; i < n; i++) {
		//Удаляем из матрицы i-ую строку и 0-ый столбец
		matrix_for_minor(matr, n, i, 0, temp);

		double det_minor = matrix_det(temp, n - 1);
		alg_dop = (sign * matr[i][0] * det_minor);

		//меняем знак
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, n - 1);
	return det;
}

