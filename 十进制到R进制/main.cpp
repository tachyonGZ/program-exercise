/*
��������

��һ��ʮ����������ת����R����

������ʽ

����ֻ��һ�У�������������a��R��a��ʾʮ����������R��ʾ��Ҫת���Ľ��ơ�1<R<=16��

�����ʽ

�������һ�У�Ϊת�����R�������������ʱ�ַ���ȫ���ô�д��ʾ������0 ��1��...��9��A��B��C��D��E��F����

��������

12 16

�������

C
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert(int a, int r)
{
	string result;
	while (a > 0)
	{
		int remain = a % r;
		if (remain < 10) result += remain + '0';
		else result += remain - 10 + 'A';
		a /= r;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	int a, r;
	cin >> a >> r;
	string res = convert(a, r);
	cout << res << endl;
	return 0;
}