/*
��������

�ںܶ������������У����Ǹ���������ֵ�Ĵ�������ͷ�ۡ����������N(N<100)�еĳ���������Ժ�����Щ��������ȷ����ֵ��������������У��ʼ���б���a����ȷ����ֵ������Ϊ����Сд��ĸ��ÿ��ǡ���������ַ����м�һ���Ǹ�ֵ�����'='��

������ʽ

�����ж��У���һ����һ������N����ʾ����ε�����������N�У�ÿ��3���ַ���Ϊһ����䡣���������N=-1��ʾ�������������Ҫ����

�����ʽ

������������ĸ��˳�����������ȷ��ֵ�ı�������������֮���ÿո�ֿ���

���û�б�����ȷ����ֵ�����none��

���ֻ�б���a��ȷ����ֵ�����a only��

��������

4
b=a
c=d
d=b
e=f
N=-1

�������

a b d
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<string> statements(n);
	for (auto &stmt : statements)
	{
		cin >> stmt;
	}

	set<char> known;
	known.insert('a');

	for (const auto& stmt : statements)
	{
		char l = stmt[0];
		char r = stmt[2];

		if (known.count(r) > 0 && known.count(l) == 0)
		{
			known.insert(l);
		}
	}

	if (known.size() == 1 && known.count('a') > 0)
	{
		cout << "a only" << endl;
	}
	else if (known.empty())
	{
		cout << "none" << endl;
	}
	else
	{
		vector<char> res(known.begin(), known.end());
		sort(res.begin(), res.end());
		copy(res.begin(), res.end(), ostream_iterator<char>(cout, " "));
	}

	return 0;
}