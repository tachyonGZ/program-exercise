/*
问题描述

在国外，每月的13号和每周的星期5都是不吉利的。特别是当13号那天恰好是星期5时，更不吉利。已知某年以及该年一月一日是星期w（w=1..7），求出这一年所有13号那天是星期5的月份，按从小到大的顺序输出月份数字。

输入形式

输入有一行，第一个整数为年份，第二个整数为该年一月一日是星期几（w）。（1<=w<=7）

输出形式

输出有一到多行，每行一个月份，表示该月的13日是星期五。

样例输入

2006 7

样例输出

1
10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> find(int year, int first_weekday)
{
	vector<int> unluckly;

	int day_in_months[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) day_in_months[1] = 29;

	int day13 = (first_weekday + 12) % 7;

	for (int month = 0; month < 12; month++)
	{
		if (day13 == 4) unluckly.push_back(month + 1);
		day13 = (day13 + day_in_months[month]) % 7;
	}

	return unluckly;
}

int main()
{
	int year, first_weekday;
	cin >> year >> first_weekday;
	vector<int> unlucky_month = find(year, first_weekday - 1);
	std::copy(unlucky_month.begin(), unlucky_month.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}