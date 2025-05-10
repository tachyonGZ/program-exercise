/*
��������

������������200λ�ķǸ������ĺ͡�

������ʽ

�����У�ÿ����һ��������200λ�ķǸ�������û�ж����ǰ��0��

�����ʽ

һ�У�����Ӻ�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��

��������

22222222222222222222
33333333333333333333

�������

55555555555555555555
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string AddLarge(const string &num1, const string &num2)
{
	int carry = 0;
	string res;
	for (size_t i = 0; i < max(num1.size(), num2.size()); i++)
	{
		int d1 = (i < num1.size()) ? num1[i] - '0' : 0;
		int d2 = (i < num2.size()) ? num2[i] - '0' : 0;
		int sum = d1 + d2 + carry;
		carry = sum / 10;
		res += (sum % 10) + '0';
	}

	if (carry > 0)
	{
		res += carry + '0';
	}

	return res;
}

int main()
{
	string num1, num2;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string numr = AddLarge(num1, num2);
	reverse(numr.begin(), numr.end());
	cout << numr << endl;
	return 0;
}