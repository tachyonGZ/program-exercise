/*
��������

��һ��R����������ת����ʮ����

������ʽ

һ�У�����һ��R���Ʊ�ʾ��������a�ͽ�����R��a��ʮ���Ʊ�ʾ�ķ�Χ��(0-65536)��1<R<=9��

�����ʽ

һ�У�a��ʮ���Ʊ�ʾ

��������

11 2

�������

3
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long convert(string a, int r)
{
	long long res = 0;
	int c = 0;
	for (auto i = a.rbegin(); i != a.rend(); i++)
	{
		int d = *i - '0';
		res += d * pow((double)r, c++);
	}
	return res;
}

int main()
{
	string a;
	int r;
	cin >> a >> r;
	long long res = convert(a, r);
	cout << res << endl;
	return 0;
}