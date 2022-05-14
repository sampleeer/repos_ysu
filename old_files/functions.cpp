#include  <iostream>
#include "Functions.h"
#include <windows.h>
using namespace std;

double input_check_element()
{
	double a;
	cin >> a;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������, �������� ���������� �����\n";
		cin >> a;
	}
	return a;
}

int input_check_dimension()
{
	int a;
	cin >> a;
	while (cin.fail() || a < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������, �������� ���������� �����\n";
		cin >> a;
	}
	return a;
}

//�������� ������� 
double** create_matrix(int n)
{
	double** matrix;// ������� ������� ��������� �����������
	matrix = new double* [n]; // ����� ������ ����������
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = input_check_element();
	return matrix;
}

//�������� ������� ��� ������������� �������
double** create_null_matrix(int n)
{
	double** matrix_result;// ������� ������� ��������� �����������
	matrix_result = new double* [n]; // ����� ������ ����������
	for (int i = 0; i < n; i++) {
		matrix_result[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_result[i][j] = 0;
	return matrix_result;
}


void changed_matrix(double** matrix, int n, double** matrix_result)// ������� ���������
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_result[i][j] = matrix[i][j];
	int numb, current_element;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			current_element = matrix[i][j];
			matrix_result[i][j] = pow(pow(current_element, 4) + 5 * pow(current_element, 2) + 3, 2);
			cout << matrix_result[i][j] << " ";
		}
		cout << endl;
	}
}

//�������� ������ ����� �������� �������
void memory_clear_matrix(double** matr, int n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
}