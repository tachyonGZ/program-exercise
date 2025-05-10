/*
问题描述
给定一个大整数，计算其阶乘。

输入形式
一行，仅含一个小于100的整数N。

输出形式
N的阶乘。

样例输入
20

样例输出
2432902008176640000
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string multiply(string num, int x)
{
	string res;

	int carry = 0;
	for (size_t i = 0; i < num.size(); i++)
	{
		int product = (num[i] - '0') * x + carry;
		res += (product % 10) + '0';
		carry = product / 10;
	}

	while (carry != 0)
	{
		res += (carry % 10) + '0';
		carry /= 10;
	}

	return res;
}

string factorial(int n)
{
	string res = "1";
	for (int i = 2; i <= n; i++)
	{
		res = multiply(res, i);
	}

	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << factorial(n) << endl;

	return 0;
}