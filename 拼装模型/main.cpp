/*
��������

Dzx���ձ������ˣ���ΪTN׼��������----һ������ģ�͡�TN���������ƴ�ã���������ģ�ͺ��Ӵ�TN��ʵ�ڱȽ�����������ϣ����Ϊ��Ѱ��һ�����ʡʱ���ƴװ������

ģ������N�������ɵģ�ÿ��TN����ѡȡ�������ƴװ��һ�������һ���µ������ֱ���õ�������ģ�͡���������ĸ��ӳ̶Ȳ�ͬ��TNÿ��ƴװ����Ҫ��ʱ��Ҳ�ǲ�ͬ�ģ������������A��B���������ǵĸ��ӳ̶ȷֱ�Ϊa��b����TNҪ�����������ƴװ��һ������Ҫ��ʱ��Ϊa+b�������������������ɵ�������ĸ��ӳ̶�Ϊa+b��

����TN�Ѿ�ͳ�Ƴ���ÿ������ĸ��ӳ̶ȣ����ܸ���������ƴװ������Ҫ����ʱ��ô��

������ʽ

Line 1�� N (1 <= N <= 10000)�������Ŀ

Line 2�� N Integers����ʾÿ������ĸ��ӳ̶�

�����ʽ

����ƴװ��������Ҫ��ʱ��

��������

5
1 4 7 3 5
�������

44
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> parts;

	for (int i = 0; i < n; i++)
	{
		int comp;
		cin >> comp;
		parts.push(comp);
	}

	long long total = 0;
	while (parts.size() > 1)
	{
		int part1 = parts.top();
		parts.pop();
		int part2 = parts.top();
		parts.pop();
		int merge = part1 + part2;
		total += merge;
		parts.push(merge);
	}

	cout << total << endl;

	return 0;
}