/*问题描述

输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。

输入形式

输入包括4行由大写字母组成的文本，每行上字符的数目不超过80个。

输出形式

输出包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用空格隔开。前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。注意：输出的第一行不能是空行。

样例输入

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> cnts(26, 0);
	for (int i = 0; i < 4; i++)
	{
		std::string line;
		std::getline(std::cin, line);
		for (auto c : line)
		{
			if (c >= 'A' && c <= 'Z')
			{
				cnts[c - 'A']++;
			}
		}
	}
	int max_cnt = 0;
	for (auto cnt : cnts)
	{
		if (max_cnt < cnt)
		{
			max_cnt = cnt;
		}
	}
	for (int i = max_cnt; i > 0; i--)
	{
		for (auto cnt : cnts)
		{
			if (cnt >= i)
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}