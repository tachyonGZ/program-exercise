/*
问题描述

菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。

给出一个正整数a，要求菲波那契数列中第a个数对1000取模的结果是多少。

输入形式

第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 1000000)。

输出形式

n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数对1000取模得到的结果。

样例输入

4
5
2
19
1

样例输出

5
1
181
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> veca;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		veca.push_back(a);
	}

	int max = *max_element(veca.begin(), veca.end());

	vector<int> fiber = {0, 1, 1};
	fiber.resize(max + 1);
	for (int i = 2; i <= max; i++)
	{
		fiber[i] = (fiber[i - 1] + fiber[i - 2]) % 1000;
	}

	for (int a : veca)
	{
		cout << fiber[a] << endl;
	}
}