#include "Martix.h"

Matrix::Matrix() {
	row = 0;
	col = 0;
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
	}
}

void Matrix::getMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> data[i][j];
		}
	}
}

void Matrix::printMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix& matrix) {
	row = matrix.row;
	col = matrix.col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			data[i][j] = matrix.data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& matrix) {
	if (col != matrix.row) {
		cout << "Matrix multiplication failed." << endl;
		return Matrix{ 0,0 };
	}
	Matrix multiMatrix(row, matrix.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < matrix.col; j++) {
			multiMatrix.data[i][j] = 0;
			for (int k = 0; k < col; k++) {
				multiMatrix.data[i][j] += data[i][k] * matrix.data[k][j];
			}
			cout << multiMatrix.data[i][j];
			if (j != matrix.col-1) cout << " ";
		}
		if (i != row-1) cout << endl;
	}
}
