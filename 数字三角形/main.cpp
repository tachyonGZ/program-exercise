/*
��������

��A��B��C��D��E��F�����������ų���ͼ��ʾ�������Ρ�

	  A

   B     F

C    D    E



�����������ֱ�ȡ[1��6]�ϵ��������Ҿ�����ͬ�����ɵ��������������ϵı���֮����ȡ������������ζ���A��ȡֵ�󣬸����ܹ������������ε�ȫ���⡣

������ʽ

����һ��ʮ���Ʊ�ʾ������A(1 <= A< =6)

�����ʽ

���У�ÿ��Ϊһ���⣬��ABCDEF��ʽ��������Ҹ�������˳���ǰ�������ɵ�������С����˳�������

��������
1

�������
145236
153426
162435
163254
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> FindCombinations(int a)
{
	vector<string> res;
	vector<int> values = {1, 2, 3, 4, 5, 6};
	values.erase(remove(values.begin(), values.end(), a), values.end());
	do {
		int b = values[0],
			c = values[1],
			d = values[2],
			e = values[3],
			f = values[4];
		if (a + b + c == c + d + e && c + d + e == e + f + a)
		{
			res.push_back(
				to_string(a) + 
				to_string(b) + 
				to_string(c) + 
				to_string(d) + 
				to_string(e) + 
				to_string(f)
			);
		}
	}while(next_permutation(values.begin(), values.end()));
	sort(res.begin(), res.end());
	return res;
}


int main()
{
	int a;
	cin >> a;
	vector<string> res = FindCombinations(a);
	copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
}