/*��������

����4��ȫ���ɴ�д��ĸ��ɵ��ı������һ����ֱֱ��ͼ������ÿ���ַ����ֵĴ�����ע�⣺ֻ������ַ��ĳ��ִ�������������հ��ַ������ֻ��߱����ŵ����������

������ʽ

�������4���ɴ�д��ĸ��ɵ��ı���ÿ�����ַ�����Ŀ������80����

�����ʽ

������������С��������һ�и���26����дӢ����ĸ����Щ��ĸ֮���ÿո������ǰ��ļ��а����ո���Ǻţ�ÿ����ĸ���ּ��Σ����������ĸ���Ϸ����һ���Ǻš�ע�⣺����ĵ�һ�в����ǿ��С�

��������

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