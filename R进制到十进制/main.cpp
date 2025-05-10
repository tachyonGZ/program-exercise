/*
问题描述

把一个R进制正整数转化成十进制

输入形式

一行，包含一个R进制表示的正整数a和进制数R，a的十进制表示的范围是(0-65536)，1<R<=9。

输出形式

一行，a的十进制表示

样例输入

11 2

样例输出

3
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long convert(string a, int r)
{
	long long res = 0;
	int c = 0;
	for (auto i = a.rbegin(); i != a.rend(); i++)
	{
		int d = *i - '0';
		res += d * pow((double)r, c++);
	}
	return res;
}

int main()
{
	string a;
	int r;
	cin >> a >> r;
	long long res = convert(a, r);
	cout << res << endl;
	return 0;
}