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
	int** matrix;
	cout << "������� ����������� �������:" << '\n';
	n = check_dimension();
	int** matrix2;// ������� ������� ��������� �����������
	matrix2 = new int*[n]; // ����� ������ ����������
	cout << "������� �������" << '\n';
	matrix = create(n);
	cout << "�������, � ����������� �������� = " << '\n';
	changed_matrix(matrix, n);
	system("pause");
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix; // ������������ ������
	return 0;
}