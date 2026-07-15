#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int rows, int cols, const char *name);
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *name);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main(void) {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX];
    int rows, cols, choice;

    printf("=====================================\n");
    printf("       MATRIX OPERATIONS PROGRAM\n");
    printf("=====================================\n");

    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX || cols > MAX || rows <= 0 || cols <= 0) {
        printf("[Error] Rows and columns must be between 1 and %d.\n", MAX);
        return 1;
    }

    inputMatrix(matA, rows, cols, "Matrix A");

    do {
        printf("\n--- Matrix Menu ---\n");
        printf("1. Addition (needs Matrix B)\n");
        printf("2. Subtraction (needs Matrix B)\n");
        printf("3. Transpose (of Matrix A)\n");
        printf("4. Display Matrix A\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matB, rows, cols, "Matrix B");
                addMatrices(matA, matB, result, rows, cols);
                displayMatrix(result, rows, cols, "Result (A + B)");
                break;

            case 2:
                inputMatrix(matB, rows, cols, "Matrix B");
                subtractMatrices(matA, matB, result, rows, cols);
                displayMatrix(result, rows, cols, "Result (A - B)");
                break;

            case 3:
                transposeMatrix(matA, result, rows, cols);
                displayMatrix(result, cols, rows, "Transpose of A");
                break;

            case 4:
                displayMatrix(matA, rows, cols, "Matrix A");
                break;

            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;

            default:
                printf("[Error] Invalid choice. Please enter 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}

/* Takes user input to fill a matrix */
void inputMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    printf("\nEnter elements for %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s[%d][%d]: ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

/* Displays a matrix in a formatted grid */
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

/* Adds two matrices element-wise */
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

/* Subtracts matrix b from matrix a element-wise */
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

/* Transposes a matrix (rows become columns) */
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}