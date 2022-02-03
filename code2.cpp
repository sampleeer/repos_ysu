/*
 * Лабороторная работа №6.2
 * Описание: дана матрица надо посчитать определитель
 потом вычесть каждую строку из нижестоящей 
 снова посчитать определитель
 * Автор: Нехаенко Павел Александрович
 * Название класса и учебной группы: пми-13 бо
 * Дата релиза: 15.12.2021
 */
#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

//функция для поэтапного вычитания одной строки из другой, она не основная ф-ция
void matrix_minus(double** src_matrix, double** dst_matrix, int n) {
	int temp_element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == n - 1) //если мы дошли до последней строки, то в неё копируем из исходной матрицы
				dst_matrix[i][j] = src_matrix[i][j];
			else {
				temp_element = src_matrix[i][j];
				dst_matrix[i][j] = temp_element - src_matrix[i + 1][j];
			}
		}
}

int main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "RUS");
	int n;
	double det = 0;
	cout << "Введите размерность квадратной матрицы A: " << '\n';
	check_input_N(n);
	cout << "Введите матрицу A: \n";
	double** original_matrix = matrix_input(n);
	double** changed_matrix = matrix_nul_create(n);
	cout << '\n' << "вид матрицы А " << '\n';
	matrix_output(original_matrix, n); //вывод введённой матрицы
	det = matrix_det(original_matrix, n);
	cout << '\n' << "Определитель матрицы A = " << det << '\n';
	cout << '\n' << "изменённая матрица А: ";
	matrix_minus(original_matrix, changed_matrix, n);
	cout << '\n';
	matrix_output(changed_matrix, n); //вывод изменённой матрицы
	det = matrix_det(changed_matrix, n);
	cout << '\n' << "Определитель изменённой матрицы A = " << det << '\n';
	matrix_memory_clear(original_matrix, n);
	matrix_memory_clear(changed_matrix, n);
	system("pause");
	return 0;
}