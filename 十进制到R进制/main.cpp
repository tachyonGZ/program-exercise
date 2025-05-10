/*
问题描述

把一个十进制正整数转化成R进制

输入形式

输入只有一行，包含两个整数a，R。a表示十进制整数，R表示需要转换的进制。1<R<=16。

输出形式

输出包含一行，为转换后的R进制整数。输出时字符号全部用大写表示，即（0 ，1，...，9，A，B，C，D，E，F）。

样例输入

12 16

样例输出

C
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert(int a, int r)
{
	string result;
	while (a > 0)
	{
		int remain = a % r;
		if (remain < 10) result += remain + '0';
		else result += remain - 10 + 'A';
		a /= r;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int a, r;
	cin >> a >> r;
	string res = convert(a, r);
	cout << res << endl;
	return 0;
}