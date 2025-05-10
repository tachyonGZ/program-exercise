/*
��������
������������200λ�ķǸ������Ļ���

������ʽ
�����У�ÿ����һ��������200λ�ķǸ�������û�ж����ǰ��0��

�����ʽ
һ�У�����˺�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��

��������
12345678900
98765432100

�������
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