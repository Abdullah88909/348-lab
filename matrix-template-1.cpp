#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4; // Assuming a 4x4 matrix size

class Matrix {
private:
    int data[SIZE][SIZE];  // 2D array to store matrix elements

public:
    // 1. Function to read matrix data from stdin
    void readFromStdin() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // 2. Function to display the matrix
    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 3. Operator overloading for matrix addition
    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 4. Operator overloading for matrix multiplication
    Matrix operator*(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Function to calculate the sum of main and secondary diagonals
    int sumOfDiagonals() const {
        int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
        for (int i = 0; i < SIZE; ++i) {
            mainDiagonalSum += data[i][i];
            secondaryDiagonalSum += data[i][SIZE - i - 1];
        }
        return mainDiagonalSum + secondaryDiagonalSum;
    }

    // 6. Function to swap two rows in the matrix
    void swapRows(int row1, int row2) {
        if (row1 < 0 || row2 < 0 || row1 >= SIZE || row2 >= SIZE) {
            cerr << "Error: Invalid row indices." << endl;
            return;
        }
        for (int i = 0; i < SIZE; ++i) {
            swap(data[row1][i], data[row2][i]);
        }
    }
};

int main() {
    Matrix mat1;
    cout << "Enter the elements of Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    Matrix mat2;
    cout << "Enter the elements of Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    int row1, row2;
    cout << "Enter two row indices to swap in Matrix 1: ";
    cin >> row1 >> row2;
    mat1.swapRows(row1, row2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
