/*
��������

�������һ��������N(N<=100)������2��N�η���ֵ��

������ʽ

����ֻ��һ��������N��

�����ʽ

���2��N�η���ֵ��

��������
50

�������
1125899906842624
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long res = 1ll;
	res = res << n;
	cout << res << endl;
	return 0;
}