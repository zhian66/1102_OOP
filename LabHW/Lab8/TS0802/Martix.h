#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	int row;
	int col;
	vector<vector<int>> data;
public:
	Matrix();
	Matrix(int r, int c);
	void getMatrix();
	void printMatrix();
	Matrix& operator=(const Matrix&);
	Matrix operator*(const Matrix&);

};