/*
问题描述

判断两个由大小写字母和空格组成的字符串在忽略大小写和压缩掉空格后是否相等

输入形式

第1行是测试数据的组数n，每组测试数据占2行，第1行是第一个字符串s1，第2行是第二个字符串s2。

每组测试数据之间有一个空行，每行数据不超过100个字符（注意字符串的长度可能为0）

输出形式

n行，相等则输出YES，否则输出NO

样例输入

3
 


a A bb BB ccc CCC
Aa BBbb CCCccc

a              dfadf              fasdf
adasddfsfsaf

样例输出

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