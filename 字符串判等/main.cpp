/*
��������

�ж������ɴ�Сд��ĸ�Ϳո���ɵ��ַ����ں��Դ�Сд��ѹ�����ո���Ƿ����

������ʽ

��1���ǲ������ݵ�����n��ÿ���������ռ2�У���1���ǵ�һ���ַ���s1����2���ǵڶ����ַ���s2��

ÿ���������֮����һ�����У�ÿ�����ݲ�����100���ַ���ע���ַ����ĳ��ȿ���Ϊ0��

�����ʽ

n�У���������YES���������NO

��������

3
 


a A bb BB ccc CCC
Aa BBbb CCCccc

a              dfadf              fasdf
adasddfsfsaf

�������

YES
YES
NO
*/

#include <iostream>
#include <string>

using namespace std;

string process(const string &s)
{
	string res;
	for (char ch : s) if (!isspace(ch)) res += tolower(ch);
	return res;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		string ls1 = process(s1);
		string ls2 = process(s2);
		if (ls1 == ls2) cout << "YES";
		else cout << "NO";
		cout << endl;
		if (i != n - 1) cin.ignore();
	}
	return 0;
}