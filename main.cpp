/*
 * ������������ ������ �6
 * ��������: ���� ������� � �������
 ����� ����� �������� ������� �� ������� x^4  + 5 * x^2 + 3 � ��������
 * �����: �������� ����� �������������
 * �������� ������ � ������� ������: ���-13 ��
 * ���� ������: 8.12.2021
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
	cout << "������� ����������� �������:" << '\n';
	n = input_check_dimension();
	cout << "������� �������" << '\n';
	double** matrix = create_matrix(n);// ������� ������� ��������� �����������
	double** matrix_result = create_null_matrix(n);// ������� ������ ������� ��������� ����������� ��� ������������� �������
	cout << "�������, � ����������� �������� = " << '\n';
	changed_matrix(matrix, n, matrix_result);
	memory_clear_matrix(matrix, n);
	memory_clear_matrix(matrix_result, n);
	system("pause");
	return 0;
}