/*
问题描述

n 位的一个整数是循环数（cyclic）的条件是：当用一个 1 到 n 之间的整数去乘它时，会得到一个将原来的数首尾相接循环移动若干数字再在某处断开而得到的数字（当数字长度大于n位时，取低n位）。也就是说，如果把原来的数字和新的数字都首尾相接，他们得到的环是相同的。只是两个数的起始数字不一定相同。例如，数字 142857 是循环数，因为：

142857 *1 = 142857

142857 *2 = 285714

142857 *3 = 428571

142857 *4 = 571428

142857 *5 = 714285

142857 *6 = 857142

写一个程序确定给定的数是否是循环数。

输入形式

输入第一行为测试数据组数n，后有n行长度为 2 位到 60 位的整数。(注意，先导的0也是合理的输入不应该被忽略,例如 "01"是 2 位数，"1" 是 1 位数。)

输出形式

对于每一个输入的整数，输出一行表明它是否是循环数。

样例输入

5
142857
142856
142858
01
0588235294117647

样例输出

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsCyclicNumber(string num)
{
	string dnum = num + num;
	for (size_t i = 2; i <= num.size(); i++)
	{
		string multi = to_string(stoll(num) * i);
		if (multi.size() > num.size()) multi = multi.substr(multi.size() - num.size());
		if (dnum.find(multi) == string::npos) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string num;
		cin >> num;
		if (IsCyclicNumber(num)) cout << num << " is cyclic" << endl;
		else cout << num << " is not cyclic" << endl;
	}
	
	return 0;
}