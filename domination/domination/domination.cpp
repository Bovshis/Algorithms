#include <vector>
#include <fstream>
#include <iostream>

long long PrefixSum(int x, std::vector<long long>& fenwick_tree)
{
    long long prefix_sum = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        prefix_sum += fenwick_tree[x];
    return prefix_sum;
}

void IncElement(int idx, int n, std::vector<long long>& fenwick_tree)
{
    for (; idx < n; idx |= idx + 1)
        fenwick_tree[idx]++;
}

int main() {
    std::ifstream input("input.txt");
    int n;
    input >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        input >> a[i];

    std::vector<long long> fenwick_tree(n);
    std::vector<long long> pref(n);

    for (int i = 0; i < n; ++i)
    {
        IncElement(a[i] - 1, n, fenwick_tree);
        pref[i] = 1ll + i - PrefixSum(a[i] - 1, fenwick_tree);

    }

    fenwick_tree.assign(n,0);
	
    long long result = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        IncElement(a[i] - 1, n, fenwick_tree);
        result += pref[i] * PrefixSum(a[i] - 2, fenwick_tree);
    }

    std::ofstream output("output.txt");
    output << result;
    output.close();

    return 0;
}