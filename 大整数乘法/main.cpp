/*
问题描述
求两个不超过200位的非负整数的积。

输入形式
有两行，每行是一个不超过200位的非负整数，没有多余的前导0。

输出形式
一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

样例输入
12345678900
98765432100

样例输出
1219326311126352690000
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string MultiplyLarge(const string &left, const string &right)
{
	vector<int> res(left.size() + right.size(), 0);

	for (size_t i = 0; i < left.size(); i++)
	{
		for (size_t j = 0; j < right.size(); j++)
		{
			int mul = (left[i] - '0') * (right[j] - '0');
			int sum = mul + res[i + j];

			res[i + j] = sum % 10;
			res[i + j + 1] += sum / 10;
		}
	}

	auto rit = find_if(res.rbegin(), res.rend(), [](int n) {return n != 0; });
	if (rit == res.rend())
	{
		return "0";
	}

	res.erase(rit.base(), res.end());

	string sres;
	for (int num : res)
	{
		sres.push_back(num + '0');
	}

	return sres;
}

int main()
{
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res = MultiplyLarge(a, b);
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}