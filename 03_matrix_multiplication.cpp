#include <iostream>
using namespace std;

int main() {
    int rows1, columns1, rows2, columns2;

    // Input dimensions of the first matrix
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> rows1 >> columns1;

    // Input dimensions of the second matrix
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> rows2 >> columns2;

    // Check if matrix multiplication is possible
    if (columns1 != rows2) {
        cout << "Matrix multiplication not possible. The number of columns of the first matrix must equal the number of rows of the second matrix." << endl;
        return 0;
    }

    int matrix1[rows1][columns1], matrix2[rows2][columns2], result[rows1][columns2];

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Initialize the result matrix with 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display the result matrix
    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



