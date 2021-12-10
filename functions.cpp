#include  <iostream>
#include "Functions.h"
#include <windows.h>
using namespace std;

int check_element()
{
	int a;
	cin >> a;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста, напишите правильный номер\n";
		cin >> a;
	}
	return a;
}

int check_dimension()
{
	int a;
	cin >> a;
	while (cin.fail() || a < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста, напишите правильный номер\n";
		cin >> a;
	}
	return a;
}

int** create(int n)
{
	int** matrix;// Создаем матрицу введенной размерности
	matrix = new int*[n]; // через массив указателей
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = check_element();
	return matrix;
}


void changed_matrix(int** matrix, int n, int** matrix2)// Функция изменения
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix2[i][j] = matrix[i][j];
	int numb, current_element;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			current_element = matrix[i][j];
			matrix2[i][j]= pow(pow(current_element, 4) + 5 * pow(current_element, 2) + 3, 2);
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}
}