#include <iostream>
#include <fstream>
#include <vector>

bool IsBinaryHeap(const std::vector<int>& binary_heap)
{
	int n = binary_heap.size();
	for (int i = 0; i < n; ++i)
	{
		if (2 * i  + 1 < n)
		{
			if (binary_heap[i] > binary_heap[2 * i + 1])
			{
				return  false;
			}
		}
		if (2 * i + 2 < n)
		{
			if (binary_heap[i] > binary_heap[2 * i + 2])
			{
				return false;
			}
		}
	}
	return  true;
}

int main()
{
	std::ifstream input("input.txt");
	int n;
	input >> n;
	std::vector<int> binary_heap(n);
	for (int i = 0; i < n; ++i)
	{
		input >> binary_heap[i];
	}
	std::ofstream output("output.txt");

	if (IsBinaryHeap(binary_heap))
	{
		output << "YES";
	}
	else
	{
		output << "NO";
	}
	output.close();
}