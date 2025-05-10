/*
������������
��д����ʵ������������������ÿ���80λ���֣��ļ������㡣
��������ʽ��

�Ӽ��̶�������������Ҫ���������λ����Ϊ0���������00083����
1. ��һ���ǳ���������A��
2. �ڶ����ǳ���������B��
�������ʽ��
���ֻ��һ�У��ǳ�����A��ȥ������B�����������Ӹߵ������������λ���֡�Ҫ�������Ϊ0����ֻ���һ��0����������Ľ�������λ����Ϊ0�����Ҹ�λ���ֽ��������
������������
234098
134098703578230056
�����������
��134098703577995958

������˵����
���������������������㣬 234098 ��134098703578230056 = ��134098703577995958��
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