/*
问题描述

将给定的整数M，从中去掉K位后使所得数最小。
例：整数：1342426735 去掉4位 结果最小为122635

输入形式
一行，第一个数为十进制表示的整数M，M位长最多为20；第二个数为整数K。

输出形式
去掉K位后的最小值。

样例输入
1342426735 4

样例输出
122635
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string RemoveDigits(string m, int k)
{
	stack<char, std::vector<char>> s;

	for (char digit : m)
	{
		while (!s.empty() && k > 0 && s.top() > digit)
		{
			s.pop();
			k--;
		}
		s.push(digit);
	}

	while (k > 0 && !s.empty())
	{
		s.pop();
		k--;
	}

	string res;
	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}
	reverse(res.begin(), res.end());

	res.erase(res.begin(), find_if(res.begin(), res.end(), [](char c) {return c != 0; }));
	
	return res.empty() ? "0" : res;
}

int main()
{
	string m;
	int k;
	cin >> m >> k;
	string res = RemoveDigits(m, k);
	cout << res << endl;
}