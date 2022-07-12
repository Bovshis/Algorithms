#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class DSU
{
public:
	int k;
	std::string str;
	int* parent_;
	int* size_;

	DSU(int n)
	{
		parent_ = new int[n + 1];
		size_ = new int[n + 1];
		for(int i = 1; i <= n; ++i)
		{
			parent_[i] = i;
			size_[i] = 1;
		}
		k = n;
	}

	~DSU()
	{
		delete[] parent_;
		delete[] size_;
	}

	int FindSet(int x)
	{
		if (x == parent_[x])
			return x;
		parent_[x] = FindSet(parent_[x]);
		return parent_[x];
	}

	void Union(int x, int y)
	{
		x = FindSet(x);
		y = FindSet(y);

		if(x != y)
		{
			k--;
			if(size_[x] < size_[y])
			{
				parent_[x] = y;
				size_[y] += size_[x];
			}else
			{
				parent_[y] = x;
				size_[x] += size_[y];
			}
		}
		
	}
	
	void UnionC(int x, int y)
	{
		x = FindSet(x);
		y = FindSet(y);

		if (k == 1)
			str.push_back('1');
		else
			str.push_back('0');

		if (x != y)
		{
			k--;
			if (size_[x] < size_[y])
			{
				parent_[x] = y;
				size_[y] += size_[x];
			}
			else
			{
				parent_[y] = x;
				size_[x] += size_[y];
			}
		}

	}
	std::string GetStr()
	{
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	std::ifstream input("input.txt");
	int n, m, q;
	input >> n >> m >> q;
	std::vector<std::pair<int, int>> roads;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		input >> u >> v;
		roads.emplace_back(u, v);
	}
	std::vector<int> number(q);
	std::vector<bool> is_destr(m,false);
	for (int i = 0; i < q; ++i)
	{
		int k;
		input >> k;
		is_destr[k - 1] = true;
		number[i] = k;
	}
	DSU dsu(n);
	for(int i = 0; i < is_destr.size(); ++i)
	{
		if(!is_destr[i])
			dsu.Union(roads[i].first, roads[i].second);
	}
	for(int i = q - 1; i >= 0; --i)
	{
		dsu.UnionC(roads[number[i] - 1].first, roads[number[i] - 1].second);
	}
	std::ofstream output("output.txt");
	output << dsu.GetStr();
	output.close();
}