/*
��������

������������M������ȥ��Kλ��ʹ��������С��
����������1342426735 ȥ��4λ �����СΪ122635

������ʽ
һ�У���һ����Ϊʮ���Ʊ�ʾ������M��Mλ�����Ϊ20���ڶ�����Ϊ����K��

�����ʽ
ȥ��Kλ�����Сֵ��

��������
1342426735 4

�������
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