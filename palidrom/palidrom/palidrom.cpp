#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#pragma warning(disable : 4996)



void lenght_pali(std::vector<std::vector<int> >& dp, const std::string& str)
{
	for(int j = 0; j < str.length(); ++j)
	{
		for(int i = j; i > -1; --i)
		{
			if(i == j)
			{
				dp[i][j] = 1;
			}else
			{
				if(str[i] == str[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}else
				{
					dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
	}
}

void build_pali(std::vector<std::vector<int> >& dp, const std::string& str, std::string& max_pali)
{
	int l = 0;
	int r = str.size() - 1;
	int pali_l = 0;
	int pali_r = dp[0][r] - 1;
	
	while (l <= r) {
		if (l == r && dp[l][r] == 1)
		{
			max_pali[pali_l] = str[l];
			pali_l++;
			l++;
		}
		else {
			if (str[l] == str[r]) {
				max_pali[pali_l] = str[l];
				max_pali[pali_r] = str[r];
				pali_l++;
				l++;
				pali_r--;
				r--;
			}
			else {
				if (dp[l + 1][r] >= dp[l][r - 1]) 
					l++;
				else 
					r--;
			}
		}
	}
}



int main()
{
	freopen("input.txt", "r", stdin);
	std::string str;
	std::cin >> str;
	std::vector<std::vector<int>> dp (str.length(), std::vector<int>(str.length(),0));
	lenght_pali(dp, str);
	
	int lenght_pali = dp[0][str.length() - 1];
	std::string max_pali;
	max_pali.resize(lenght_pali);
	build_pali(dp, str, max_pali);

	freopen("output.txt", "w", stdout);
	std::cout << lenght_pali << "\n" << max_pali;
	
}