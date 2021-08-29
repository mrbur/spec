#pragma once

class Matrix {
	private:
		float** matrix;
		int cols;
		float deternminant;

		float getDeterminant(float** matrixArr, int mSize) const {
			if (mSize == 2) {
				return matrixArr[0][0] * matrixArr[1][1] - matrixArr[1][0] * matrixArr[0][1];
			}
			int sign = 1;
			int submatrixCol = 0, subMatrixRow = 0;
			float sum = 0;
			
			for (int i = 0; i < mSize; i++) {
				float** subMatrixArr = new float* [mSize - 1];
				for (int i = 0; i < mSize - 1; i++) {
					subMatrixArr[i] = new float[mSize - 1];
				}
				for (int j = 1; j < mSize; j++) {
					for (int k = 0; k < mSize; k++) {
						if (i != k) {
							subMatrixArr[subMatrixRow][submatrixCol] = matrixArr[j][k];
							submatrixCol++;
						}
					}
					subMatrixRow++;
					submatrixCol = 0;
				}
				subMatrixRow = 0;
				
				Matrix subMatrix(subMatrixArr, mSize - 1);
				sum += matrixArr[0][i] * sign * subMatrix.getDeterminant();
				sign *= -1;
			}
			return sum;
		}
	public:
		Matrix(float** arr, int n) {
			deternminant = getDeterminant(arr, n);
		}

		~Matrix() {
			for (int i = 0; i < cols; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		float getDeterminant() const {
			return deternminant;
		}
};