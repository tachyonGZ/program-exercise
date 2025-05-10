/*
问题描述

任意给定一个正整数N(N<=100)，计算2的N次方的值。

输入形式

输入只有一个正整数N。

输出形式

输出2的N次方的值。

样例输入
50

样例输出
1125899906842624
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long res = 1ll;
	res = res << n;
	cout << res << endl;
	return 0;
}