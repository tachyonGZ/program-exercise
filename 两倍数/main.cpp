//问题描述
//
//给定2到15个不同的正整数，你的任务是计算这些数里面有多少个数对满足：数对中一个数是另一个数的两倍。
//
//比如给定1 4 3 2 9 7 18 22，得到的答案是3，因为2是1的两倍，4是2的两倍，18是9的两倍。
//
//输入形式
//
//输入包括多组测试数据。每组数据包括一行，给出2到15个两两不同且小于100的正整数。每一行最后一个数是0，表示这一行的结束后，这个数不属于那2到15个给定的正整数。输入的最后一行只包括一个整数 - 1，这行表示输入数据的结束，不用进行处理。
//
//输出形式
//
//对每组输入数据，输出一行，给出有多少个数对满足其中一个数是另一个数的两倍。
//
//样例输入
//
//1 4 3 2 9 7 18 22 0
//
//2 4 8 10 0
//
//7 5 11 13 1 3 0
//
//- 1
//
//样例输出
//
//3
//
//2
//
//0
#include <iostream>
#include <vector>
#include <algorithm>

void c(std::vector<int> &a)
{
	int sum = 0;
	std::sort(a.begin(), a.end());
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = i + 1; j < a.size(); j++)
		{
			if (a[j] == 2 * a[i])
			{
				sum++;
			}
		}
	}
	std::cout << sum << '\n';
}

int main ()
{
	std::vector<int> a;
	while (true)
	{
		int n = 0;
		std::cin >> n;
		if (0 == n)
		{
			c(a);
			a.clear();
			continue;
		}
		if (-1 == n) break;
		a.push_back(n);
	}
	return 0;
}