/*
问题描述

在很多程序设计语言中，忘记给变量赋初值的错误常令人头疼。请编程求出含N(N<100)行的程序段运行以后有哪些变量中有确定的值。在下面的问题中，最开始仅有变量a中有确定的值。变量为单个小写字母，每行恰好有三个字符，中间一个是赋值运算符'='。

输入形式

输入有多行，第一行有一个整数N，表示程序段的行数。以下N行，每行3个字符，为一条语句。最后行数据N=-1表示输入结束，不需要处理。

输出形式

输出结果，按字母表顺序给出所有有确定值的变量名，各变量之间用空格分开。

如果没有变量有确定的值，输出none。

如果只有变量a有确定的值，输出a only。

样例输入

4
b=a
c=d
d=b
e=f
N=-1

样例输出

a b d
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<string> statements(n);
	for (auto &stmt : statements)
	{
		cin >> stmt;
	}

	set<char> known;
	known.insert('a');

	for (const auto& stmt : statements)
	{
		char l = stmt[0];
		char r = stmt[2];

		if (known.count(r) > 0 && known.count(l) == 0)
		{
			known.insert(l);
		}
	}

	if (known.size() == 1 && known.count('a') > 0)
	{
		cout << "a only" << endl;
	}
	else if (known.empty())
	{
		cout << "none" << endl;
	}
	else
	{
		vector<char> res(known.begin(), known.end());
		sort(res.begin(), res.end());
		copy(res.begin(), res.end(), ostream_iterator<char>(cout, " "));
	}

	return 0;
}