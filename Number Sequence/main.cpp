//问题描述
//
//A number sequence is defined as follows :
//
//f(1) = 1， f(2) = 1， f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//
//Given A， B， and n， you are to calculate the value of f(n).
//
//输入形式
//
//The input consists of multiple test cases.Each test case contains 3 integers A， B and n on a single line(1 <= A， B <= 1000， 1 <= n <= 100，000，000).Three zeros signal the end of input and this test case is not to be processed.
//
//输出形式
//
//For each test case， print the value of f(n) on a single line.
//
//样例输入
//
//1 1 3
//
//1 2 10
//
//0 0 0
//
//样例输出
//
//2
//
//5

#include <iostream>
#include <array>

int f(int a, int b, int n)
{
	std::array<int, 3> f = {1, 1, 0};
	for (int i = 2; i != n; i++)
	{
		f[2] = (a * f[1] + b * f[0]) % 7;
		f[0] = f[1];
		f[1] = f[2];
	}
	return f[2];
}

int main()
{
	while (true)
	{
		int a, b, n;
		std::cin >> a >> b >> n;
		if (a == 0 && b == 0 && 0 == n) break;
		std::cout << f(a, b, n) << '\n';
	}
	return 0;
}