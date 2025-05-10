/*
问题描述

You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in detail how the strings are generated and inserted into the original message. To validate your method， however， it is necessary to write a program that checks if the message is really encoded in the final string.

Given two strings s and t， you have to decide whether s is a subsequence of t，i.e. if you can remove characters from t such that the concatenation of the remaining characters is s.

输入形式

The input contains several test cases. Each is specified by two strings s, t of alphanumeric ASCII characters separated by white space. The length of s and t will no more than 100000.

输出形式

For each test case output "Yes"， if s is a subsequence of t，otherwise output "No".

样例输入

4
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

样例输出

Yes
No
Yes
No
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s, t;
		cin >> s >> t;
		size_t ps = 0, pt = 0;
		while (ps < s.size() && pt < t.size())
		{
			if (s[ps] == t[pt]) ps++;
			pt++;
		}
		if (ps == s.length()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}