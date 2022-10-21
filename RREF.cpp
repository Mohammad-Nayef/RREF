#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int row, column, index_of_one = 0;

void fill(vector<vector<double>>& matrix) {
	cout << "Now enter the matrix:\n";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void first_nonzero(vector<vector<double>>& matrix) {
	//finding the 1st non-zero element among all the rows
	//and swap rows to make the 1st row has a leading non-zero
	for (int j = 0; j < column; j++)
	{
		for (int i = 0; i < row; i++)
		{
			if (matrix[i][j]) { 
				for (int k = 0; k < column; k++)
				{
					swap(matrix[0][k], matrix[i][k]);
				}
				break;
			}
		}
	}
}

void make_leading_one(vector<vector<double>>& matrix, int current_row) {
	for (int i = 0; i < column; i++)
	{
		if (matrix[current_row][i]) {
			index_of_one = i;
			double x = matrix[current_row][i];
			for (; i < column; i++)
			{
				matrix[current_row][i] /= x;
			}
			break;
		}
	}
}

void make_zeros_under(vector<vector<double>>& matrix, int current_row) {
	for (int i = current_row + 1; i < row; i++)
	{
		if (matrix[i][index_of_one]) {
			int x = matrix[i][index_of_one];
			for (int j = index_of_one; j < column; j++)
			{
				matrix[i][j] = -1 * x * matrix[current_row][j] + matrix[i][j];
			}
		}
	}
}

void make_zeros_above(vector<vector<double>>& matrix, int current_row) {
	for (int i = current_row - 1; i >= 0; i--)
	{
		if (matrix[i][index_of_one]) {
			int x = matrix[i][index_of_one];
			for (int j = index_of_one; j < column; j++)
			{
				matrix[i][j] = -1 * x * matrix[current_row][j] + matrix[i][j];
			}
		}
	}
}

void print(vector<vector<double>>& matrix) {
	int i, j;
	cout << "The result:\n";
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < column; j++)
		{
			cout << matrix[i][j]<<'\t';
		}
		cout << endl << endl;
	}
}

int main() {
	cout << "Enter the number of rows:\n";
	cin >> row ;
	cout << "Enter the number of columns:\n";
	cin >> column;
	vector<vector<double>> matrix(row, vector<double>(column));

	fill(matrix);

	if(matrix[0][0] == 0) 
		first_nonzero(matrix);

	for (int i = 0; i < row; i++)
	{
		make_leading_one(matrix, i);
		make_zeros_under(matrix, i);
		if(i)
			make_zeros_above(matrix, i);
	}

	print(matrix);
}
