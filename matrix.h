#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

double** minor(double* matrix[], int size, int deleted_row, int deleted_column);

double matrix_determinant(double* matrix[], int size);

double** inverse_matrix(double* matrix[], int size);

void clear(double* arr[], int size);

void mult(double* mat1[], double* mat2[], int size);




#endif // MATRIX_OPERATIONS