#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//проверка введеного натурального числа
void correct_input_N(int& num);

//проверка введеного действительного числа
void correct_input_R(double& num);

//создание нулевой квадратной матрицы
double** matrix_nul_create(int n);

//отчистка памяти после создания матрицы
void matrix_memory_clear(double** matr, int n);

//ввод начальной квадратной матрицы
double** matrix_input(int n);

//вывод начальной квадратной матрицы
void matrix_output(double** orig_matr, int n);

//Возвращает матрицу для нахождения минора, путем вырчеркивания row-ой строки и col-того столбца матрицы matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr);

//Рекурсивная функция для нахождения определителя матрицы. 
int matrix_det(double** matr, int n);



#endif // MATRIX_OPERATIONS