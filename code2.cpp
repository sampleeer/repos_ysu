#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

//функция для поэтапного вычитания одной строки из другой, она не основная ф-ция
void matrix_minus(double** orig_matr, double** changed_matrix, int n) {
    int temp_element;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == n - 1) //если мы дошли до последней строки, то в неё копируем из исходной матрицы
                changed_matrix[i][j] = orig_matr[i][j];
            else {
                temp_element = orig_matr[i][j];
                changed_matrix[i][j] = temp_element - orig_matr[i + 1][j];
            }
        }
}

int main(int argc, const char* argv[])
{
    setlocale(LC_ALL, "RUS");
    int n;
    double det = 0;
    cout << "Введите размерность квадратной матрицы A: ";
    correct_input_N(n);
    cout << "Введите матрицу A: \n";
    double** original_matrix = matrix_input(n);
    double** changed_matrix = matrix_nul_create(n);
    cout << "вид матрицы А " << '\n';
    matrix_output(original_matrix, n); //вывод введённой матрицы
    det = matrix_det(original_matrix, n);
    cout << '\n' << "Определитель матрицы A = " << det << '\n';
    cout << "изменённая матрица А: \n";
    matrix_minus(original_matrix, changed_matrix, n);
    cout << '\n'; 
    matrix_output(changed_matrix, n); //вывод изменённой матрицы
    det = matrix_det(changed_matrix, n);
    cout << "Определитель изменённой матрицы A = " << det << '\n';
    matrix_memory_clear(original_matrix, n);
    matrix_memory_clear(changed_matrix, n);
	system("pause");
	return 0;
}