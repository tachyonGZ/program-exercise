/*
问题描述
求2个大的正整数相除的商

输入形式
第1行是测试数据的组数n，每组测试数据占2行，第1行是被除数，第2行是除数。每组测试数据之间有一个空行，每行数据不超过100个字符

输出形式
n行，每组测试数据有一行输出是相应的整数商

样例输入
3
2405337312963373359009260457742057439230496493930355595797660791082739646
2987192585318701752584429931160870372907079248971095012509790550883793197894

10000000000000000000000000000000000000000
10000000000

5409656775097850895687056798068970934546546575676768678435435345
1

样例输出
0
1000000000000000000000000000000
5409656775097850895687056798068970934546546575676768678435435345
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string LargeDivide(const string &dividend, const string &divisor)
{
	string result;
	string current;
	for (size_t i = 0; i < dividend.length(); i++)
	{
		current += dividend[i];
		current.erase(
			current.begin(),
			find_if(
				current.begin(),
				current.end(),
				[](char c) {
					return c != '0';
				}
			)
		);

		if (current.length() < divisor.length() || (current.length() == divisor.length() && current < divisor))
		{
			result += '0';
			continue;
		}

		int count = 0;
		while (current.length() > divisor.length() || (current.length() == divisor.length() && current >= divisor))
		{
			string temp;
			reverse_copy(current.begin(), current.end(), back_inserter(temp));
			string temp_divisor;
			reverse_copy(divisor.begin(), divisor.end(), back_inserter(temp_divisor));
			int carry = 0;
			for (size_t j = 0; j < current.length(); j++)
			{
				int l = temp[j] - '0';
				int r = j < temp_divisor.length() ? temp_divisor[j] - '0' : 0;
				int sub = l - r - carry;
				if (sub < 0)
				{
					sub += 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				temp[j] = sub + '0';
			}

			reverse_copy(temp.begin(), temp.end(), current.begin());
			current.erase(
				current.begin(),
				find_if(
					current.begin(),
					current.end(),
					[](char c) {
						return c != '0';
					}
				)
			);
			count++;
		}

		result += count + '0';
	}

	result.erase(
		result.begin(),
		find_if(
			result.begin(),
			result.end(),
			[](char c) {
				return c != '0';
			}
		)
	);

	return result.empty() ? "0" : result;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string dividend, divisor;
		cin >> dividend >> divisor;
		cout << LargeDivide(dividend, divisor) << endl;
	}

	return 0;
}