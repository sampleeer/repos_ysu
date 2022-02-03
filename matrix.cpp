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
	while (cin.fail()) {
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
			cout << setw(10) << fixed << setprecision(0) << orig_matr[i][j];
		cout << endl;
	}
}

//������� �������� ���������� ������� � ������
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

//������� ��������� ���������� ������� �� �����
double** matrix_multiply_num(double** matr, int n, int num) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = num * matr[i][j];
	return out_matr;
}

//������� �������� ���������� ������
double** matrix_addition_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			out_matr[i][j] = matr_1[i][j] + matr_2[i][j];
	return out_matr;
}

//������� ������������ ���������� ������
double** matrix_multiply_matrix(double** matr_1, double** matr_2, int n) {
	double** out_matr = matrix_nul_create(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				out_matr[i][j] += matr_1[i][k] * matr_2[k][j];
	return out_matr;
}
