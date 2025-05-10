/*
问题描述

Dzx从日本回来了，并为TN准备了礼物----一个恐龙模型。TN想把它尽快拼好，但是由于模型很庞大，TN又实在比较懒，所以他希望你为他寻找一个最节省时间的拼装方案。

模型是由N个零件组成的，每次TN可以选取两个零件拼装在一起来组成一个新的零件，直到得到完整的模型。由于零件的复杂程度不同，TN每次拼装所需要的时间也是不同的，对于两个零件A和B，假设他们的复杂程度分别为a和b，则TN要将这两个零件拼装在一起所需要的时间为a+b，而这由两个零件所组成的新零件的复杂程度为a+b。

现在TN已经统计出了每个零件的复杂程度，你能告诉他最快的拼装方发需要多少时间么？

输入形式

Line 1： N (1 <= N <= 10000)，零件数目

Line 2： N Integers，表示每个零件的复杂程度

输出形式

最快的拼装方案所需要的时间

样例输入

5
1 4 7 3 5
样例输出

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