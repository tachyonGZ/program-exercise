/*
【问题描述】
编写程序实现两个超长正整数（每个最长80位数字）的减法运算。
【输入形式】

从键盘读入两个整数，要考虑输入高位可能为0的情况（如00083）。
1. 第一行是超长正整数A；
2. 第二行是超长正整数B；
【输出形式】
输出只有一行，是长整数A减去长整数B的运算结果，从高到低依次输出各位数字。要求：若结果为0，则只输出一个0；否则输出的结果的最高位不能为0，并且各位数字紧密输出。
【输入样例】
234098
134098703578230056
【输出样例】
－134098703577995958

【样例说明】
进行两个正整数减法运算， 234098 －134098703578230056 = －134098703577995958。
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsGreater(const string &left, const string &right)
{
	if (left.size() != right.size())
	{
		return left.size() > right.size();
	}
	return left > right;
}

string SubtractLarge(const string &left, const string &right)
{
	string res;

	int borrow = 0;
	for (size_t i = 0; i < left.size(); i++)
	{
		int digit_left = left[i] - '0';
		int digit_right = i < right.size() ? right[i] - '0' : 0;
	
		digit_left -= borrow;
		if (digit_left < digit_right)
		{
			digit_left += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}

		res += digit_left - digit_right + '0';
	}

	auto rit = find_if(res.rbegin(), res.rend(), [](char c){return c != '0';});
	if (rit == res.rend())
	{
		return "0";
	}
	
	return string(res.begin(), rit.base());
}

int main()
{
	string a, b;
	cin >> a >> b;
	a.erase(0, min(a.find_first_not_of('0'), a.size()));
	b.erase(0, min(b.find_first_not_of('0'), b.size()));
	
	bool negative = false;
	if (IsGreater(b, a))
	{
		negative = true;
		swap(a, b);
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res = SubtractLarge(a, b);
	if (negative)
	{
		res += "-";
	}
	reverse(res.begin(), res.end());
	
	cout << res << endl;
	return 0;
}