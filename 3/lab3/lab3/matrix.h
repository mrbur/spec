#pragma once

class Matrix {
	private:
		float** matrix;
		int cols;
		float deternminant;

		float getDeterminant(float** arr, int n) const {
			if (n == 2) {
				return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
			}
			int sign = 1;
			int k = 0, l = 0;
			float sum = 0;
			
			for (int i = 0; i < n; i++) {
				float** subArray = new float* [n - 1];
				for (int i = 0; i < n-1; i++) {
					subArray[i] = new float[n-1];
				}
				for (int j = 1; j < n; j++) {
					for (int m = 0; m < n; m++) {
						if (i != m) {
							subArray[l][k] = arr[j][m];
							k++;
						}
					}
					l++;
					k = 0;
				}
				l = 0;
				
				sum += arr[0][i] * sign * getDeterminant(subArray, n - 1);
				sign *= -1;
			}
			return sum;
		}
	public:
		Matrix(float** arr, int n) {
			deternminant = getDeterminant(arr, n);
		}

		float getDeterminant() const {
			return deternminant;
		}
};