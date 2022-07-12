#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fstream>

#pragma warning(disable : 4996)

int min_multiplication(const std::vector<int> &matrices_size)
{
	int n = matrices_size.size() - 1;
	int** dp = new int*[n];
	for (int count = 0; count < n; count++)
		dp[count] = new int[n];

	for (int i = 0; i < n; ++i) {
		dp[i][i] = 0;
	}

	for (int l = 1; l < n; ++l) {
		for (int i = 0; i < n - l; ++i) {
			int j = i + l;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; ++k) {
				dp[i][j] = std::min(dp[i][j],
					dp[i][k] + dp[k + 1][j] + matrices_size[i] * matrices_size[k + 1] * matrices_size[j + 1]);
			}
		}
	}
	return dp[0][n - 1];
	
}

int main()
{
	FILE* input = fopen("input.txt", "r");
	int n;
	fscanf(input, "%d\n", &n);
	std::vector<int> matrices_size(n + 1);
	int a, b;
	fscanf(input, "%d %d\n", &a, &b);
	matrices_size[0] = a;
	matrices_size[1] = b;
	
	for (int i = 1; i < n; ++i)
	{
		fscanf(input, "%d %d\n", &a, &b);
		matrices_size[i + 1] = b;
	}
	fclose(input);

	FILE* output = fopen("output.txt", "w");
	fprintf(output, "%d", min_multiplication(matrices_size) );
	

	return 0;
}
