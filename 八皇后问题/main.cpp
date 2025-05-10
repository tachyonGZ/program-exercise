/*
��������

���¹���������˶���������ʺ�����ںᡢ����б���ϲ��޲����سԵ��������ӡ���ν�8���ʺ���������ϣ���8 * 8�����񣩣�ʹ����˭Ҳ���ܱ��Ե�������������İ˻ʺ����⡣

����ĳ������Ҫ���8�ʺ�İڷŷ���������һ���ʺ�a��֮��Ӧ����a=b1b2...b8������biΪ��Ӧ�ڷ��е�i�лʺ��������������Ѿ�֪��8�ʺ�����һ����92��⣨��92����ͬ�Ļʺ󴮣���

����һ����b��Ҫ�������b���������ıȽ��������ģ��ʺ�x���ڻʺ�y֮ǰ�����ҽ�����x��Ϊ����ʱ��yС��

������ʽ

��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������b(1 <= b <= 92)

�����ʽ

�����n�У�ÿ�������Ӧһ�����롣���Ӧ��һ�����������Ƕ�Ӧ��b�Ļʺ󴮡�

��������
2
1
92

�������
15863724
84136275
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solutions;
bool cols[8];
bool diag1[15];
bool diag2[15];

void backtrace(int row, string current)
{
	if (row == 8)
	{
		solutions.push_back(current);
		return;
	}

	for (int col = 0; col < 8; col++)
	{
		if (cols[col] || diag1[row - col + 7] || diag2[row + col])
			continue;

		cols[col] = diag1[row - col + 7] = diag2[row + col] = true;
		backtrace(row + 1, current + to_string(col + 1));
		cols[col] = diag1[row - col + 7] = diag2[row + col] = false;
	}
}

int main()
{
	int n;
	cin >> n;
	backtrace(0, "");


	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		cout << solutions[b - 1] << endl;
	}
}