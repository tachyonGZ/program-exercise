/*
��������

��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���

������ʽ

��һ���ǲ������ݵ���Ŀt��0 <= t <= 20��������ÿ�о�������������M��N���Կո�ֿ���1<=M��N<=10��

�����ʽ

�������ÿ������M��N����һ�������Ӧ��K��

��������

1
7 3

�������

8
*/

#include <iostream>

using namespace std;

int apple(int m, int n)
{
	if (m < 0)
	{
		return 0;
	}

	if (m == 1 || n == 1)
	{
		return 1;
	}

	return apple(m, n - 1) + apple(m - n, n);
}

int main()
{
	int k;
	cin >> k;

	while (k--)
	{
		int m, n;
		cin >> m >> n;

		cout << apple(m, n) << endl;
	}

	return 0;
}