/*
��������

�Ʋ�����������ָ����������: ���еĵ�һ���͵ڶ�������Ϊ1��������ÿ����������ǰ��2����֮�͡�

����һ��������a��Ҫ��Ʋ����������е�a������1000ȡģ�Ľ���Ƕ��١�

������ʽ

��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������a(1 <= a <= 1000000)��

�����ʽ

n�У�ÿ�������Ӧһ�����롣���Ӧ��һ����������Ϊ�Ʋ����������е�a������1000ȡģ�õ��Ľ����

��������

4
5
2
19
1

�������

5
1
181
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> veca;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		veca.push_back(a);
	}

	int max = *max_element(veca.begin(), veca.end());

	vector<int> fiber = {0, 1, 1};
	fiber.resize(max + 1);
	for (int i = 2; i <= max; i++)
	{
		fiber[i] = (fiber[i - 1] + fiber[i - 2]) % 1000;
	}

	for (int a : veca)
	{
		cout << fiber[a] << endl;
	}
}