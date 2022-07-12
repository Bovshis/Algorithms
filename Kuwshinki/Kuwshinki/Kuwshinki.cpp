#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#pragma warning(disable : 4996)

int prig_skok(int n, std::vector<int> &komariki)
{
	switch (n)
	{
	case 1:
		return komariki[0];
	case 2:
		return -1;
	case 3:
		return komariki[0] + komariki[2];
	case 4:
		return komariki[0] + komariki[3];
	case 5:
		return komariki[0] + komariki[2] + komariki[4];
	default:
		int* dead_komariki = new int[n];
		dead_komariki[0] = komariki[0];
		dead_komariki[2] = komariki[0] + komariki[2];
		dead_komariki[3] = komariki[0] + komariki[3];
		dead_komariki[4] = dead_komariki[2] + komariki[4];
		for(int i = 5; i < n; ++i)
		{
			dead_komariki[i] = komariki[i] + std::max(dead_komariki[i - 2], dead_komariki[i - 3]);
		}
		return dead_komariki[n - 1];
		
	}
}

int main()
{
	FILE* input = fopen("input.txt", "r");
	int n;
	fscanf(input, "%d\n", &n);
	std::vector<int> komariki(n);
	for(int i = 0; i < n; ++i)
	{
		int k;
		fscanf(input, "%d ", &k);
		komariki[i] = k;
	}
	fclose(input);

	FILE* output = fopen("output.txt", "w");
	fprintf(output, "%d", prig_skok(n, komariki));

	return 0;
}
