#include <iostream>
#include <fstream>
#include <vector>

int BinarySearch(std::vector<int>& arr, int x)
{
	int l = 0, r = arr.size();
	
	while (l < r)
	{
		int k = l + (r - l) / 2;
		
		if (x == arr[k])
		{
			return 1;
		}
		if(x < arr[k])
		{
			r = k;
		}else
		{
			l = k + 1;
		}
	}
	return 0;
}

int UpperEqualsBound(std::vector<int>& arr, int x)
{
	int l = 0, r = arr.size();
	while (l < r)
	{
		int k = l + (r - l) / 2;
		
		if (x <= arr[k])
		{
			r = k;
		}
		else
		{
			l = k + 1;
		}
	}
	return l;
}

int UpperBound(std::vector<int>& arr, int x)
{
	int l = 0, r = arr.size();
	while (l < r)
	{
		int k = l + (r - l) / 2;

		if (x < arr[k])
		{
			r = k;
		}
		else
		{
			l = k + 1;
		}
	}
	return l;
}

template <class T>
bool BS(const std::vector<T
>& a, const T& x) {
	size_t l = 0; size_t r = a.size();
	// [l, r)
	while (l < r) {
		size_t m = (l + r + 1) / 2;
		if (a[m] == x) {
			return true;
		}
		else if (a[m] < x) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	return false;
}


int main()
{
    int n;
	std::vector<int> arr({ 1,2,3,4});

	std::cout << BS(arr, 6);
	
	
}
