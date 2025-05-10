/*
 ��������

Bob �� Alice ��ʼʹ��һ��ȫ�µı���ϵͳ������һ�ֻ���һ��˽��Կ�׵ġ�����ѡ����n����ͬ����a1 �� . . .��an�����Ƕ�����0С�ڵ���n�����ܹ������£������ܵ���Ϣ�������������Կ���£���Ϣ�е��ַ�����Կ�е�����һһ��Ӧ��������Ϣ��λ��iλ�õ���ĸ����д��������Ϣ�ĵ�ai��λ�ã� ai ��λ��iλ�õ���Կ��������Ϣ��˷������ܣ�һ������ k �Ρ�

��Ϣ����С�ڵ���n�������Ϣ�� n �̣������λ���ÿո��ֱ����Ϣ����Ϊn��

������� Alice �� Bob дһ�����򣬶�����Կ��Ȼ�������ܴ��� k ��Ҫ���ܵ���Ϣ�������ܹ�����Ϣ���ܡ�

������ʽ

����������顣ÿ���һ����һ������n�� 0 < n <= 200. ���������а���n����ͬ�����֡����ֶ��Ǵ���0С�ڵ���n�ġ�����ÿ�а���һ��k��һ����Ϣ�ַ���������֮���ÿո�񿪡�ÿ���Ի��з����������з�����Ҫ���ܵ���Ϣ��ÿ��������һ��ֻ��һ��0�����һ�������һ�У�����ֻ��һ��0��

�����ʽ

����ж���飬ÿ�����Ӧһ������顣ÿ������������е���Ϣ�������ܺ���ַ�����˳��������˳����ͬ�����м��ܺ���ַ����ĳ��ȶ��� n��ÿһ�������һ�����С�

��������

10
4 5 3 7 2 8 1 6 10 9
1 Hello Bob
1995 CERC
0
0

�������

BolHeol  b
C RCE
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void encrypt(const vector<int> &keys, int k, string &plain)
{
	plain.resize(keys.size(), ' ');
	for (int i = 0; i < k; i++)
	{
		string temp(plain.size(), ' ');
		for (size_t j = 0; j < plain.size(); j++)
		{
			temp[keys[j] - 1] = plain[j];
		}
		plain.swap(temp);
	}
}

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (0 == n) break;
		vector<int> keys(n);
		for (int i = 0; i < n; i++)
		{
			cin >> keys[i];
		}
		while (true)
		{
			string line;
			getline(cin, line);
			if (line == "0") break;
			istringstream iss(line);
			int k;
			iss >> k;
			iss.ignore();
			getline(iss, line);
			encrypt(keys, k, line);
			cout << line << endl;
		}
	}
	return 0;
}