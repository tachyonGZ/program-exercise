/*
问题描述

将A、B、C、D、E、F这六个变量排成如图所示的三角形。

	  A

   B     F

C    D    E



这六个变量分别取[1，6]上的整数，且均不相同，构成的三角形三条边上的变量之和相等。当给出三角形顶点A的取值后，给出能构成这样三角形的全部解。

输入形式

仅含一个十进制表示的整数A(1 <= A< =6)

输出形式

多行，每行为一个解，按ABCDEF形式输出，并且各解的输出顺序是按其所组成的整数由小到大顺序输出。

样例输入
1

样例输出
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