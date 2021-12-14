#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

//�������� ��������� ������������ �����
void correct_input_N(int& num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������� ����������� �������� ����������!\n";
		cin >> num;
	}
}

//�������� ��������� ��������������� �����
void correct_input_R(double& num) {
	cin >> num;
	while (cin.fail() ) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������� ������������ �������� ����������!\n";
		cin >> num;
	}
}

//�������� ������� ���������� �������
double** matrix_nul_create(int n) {
	double** out_matr = new double* [n];
	for (int i = 0; i < n; i++)
		out_matr[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = 0;
	return out_matr;
}

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}

//���� ��������� ���������� �������
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

//����� ��������� ���������� �������
void matrix_output(double** orig_matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << orig_matr[i][j];
		cout << endl;
	}
}

//���������� ������� ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr) {
	int row_shift = 0; //�������� ������� ������ � �������
	int col_shift = 0; //�������� ������� ������� � �������
	for (int i = 0; i < n - 1; i++) {
		//���������� row-�� ������
		if (i == row)
			row_shift = 1;
		for (int j = 0; j < n - 1; j++) {
			//���������� col-�� �������
			if (j == col)
				col_shift = 1;
			minor_matr[i][j] = matr[i + row_shift][j + col_shift];
		}
	}
}

//����������� ������� ��� ���������� ������������ �������. 
int matrix_det(double** matr, int n) {
	//��������� �������, ���������� ������������� i-�� ������ � 0-��� �������
	double** temp = matrix_nul_create(n - 1);
	double det = 0;
	double alg_dop = 0;
	//���� ����� �� ������ 2�2, �� ����������� ���
	if (n == 2) {
		alg_dop = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return alg_dop;
	}
	//������� ������ �� ��������
	if (n == 1) {
		return matr[0][0];
	}
	//���� ��� ������������ ��������������� ����������
	int sign = 1;
	for (int i = 0; i < n; i++) {
		//������� �� ������� i-�� ������ � 0-�� �������
		matrix_for_minor(matr, n, i, 0, temp);

		double det_minor = matrix_det(temp, n - 1);
		alg_dop = (sign * matr[i][0] * det_minor);

		//������ ����
		sign *= -1;
		det += alg_dop;
	}
	matrix_memory_clear(temp, n - 1);
	return det;
}

