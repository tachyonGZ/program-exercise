/*
问题描述

求两个不超过200位的非负整数的和。

输入形式

有两行，每行是一个不超过200位的非负整数，没有多余的前导0。

输出形式

一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

样例输入

22222222222222222222
33333333333333333333

样例输出

55555555555555555555
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string AddLarge(const string &num1, const string &num2)
{
	int carry = 0;
	string res;
	for (size_t i = 0; i < max(num1.size(), num2.size()); i++)
	{
		int d1 = (i < num1.size()) ? num1[i] - '0' : 0;
		int d2 = (i < num2.size()) ? num2[i] - '0' : 0;
		int sum = d1 + d2 + carry;
		carry = sum / 10;
		res += (sum % 10) + '0';
	}

	if (carry > 0)
	{
		res += carry + '0';
	}

	return res;
}

int main()
{
	string num1, num2;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string numr = AddLarge(num1, num2);
	reverse(numr.begin(), numr.end());
	cout << numr << endl;
	return 0;
}