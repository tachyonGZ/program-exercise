/*
��������

�ڹ��⣬ÿ�µ�13�ź�ÿ�ܵ�����5���ǲ������ġ��ر��ǵ�13������ǡ��������5ʱ��������������֪ĳ���Լ�����һ��һ��������w��w=1..7���������һ������13������������5���·ݣ�����С�����˳������·����֡�

������ʽ

������һ�У���һ������Ϊ��ݣ��ڶ�������Ϊ����һ��һ�������ڼ���w������1<=w<=7��

�����ʽ

�����һ�����У�ÿ��һ���·ݣ���ʾ���µ�13���������塣

��������

2006 7

�������

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