#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//�������� ��������� ������������ �����
void correct_input_N(int& num);

//�������� ��������� ��������������� �����
void correct_input_R(double& num);

//�������� ������� ���������� �������
double** matrix_nul_create(int n);

//�������� ������ ����� �������� �������
void matrix_memory_clear(double** matr, int n);

//���� ��������� ���������� �������
double** matrix_input(int n);

//����� ��������� ���������� �������
void matrix_output(double** orig_matr, int n);

//���������� ������� ��� ���������� ������, ����� ������������� row-�� ������ � col-���� ������� ������� matr;
void matrix_for_minor(double** matr, int n, int row, int col, double** minor_matr);

//����������� ������� ��� ���������� ������������ �������. 
int matrix_det(double** matr, int n);



#endif // MATRIX_OPERATIONS