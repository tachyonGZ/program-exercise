/*
样例输入

2
female 4.5 4.0 115 37 200
male 3.9 3.5 155 36 301

样例输出

normal
3
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Blood
{
	string sex;
	double wbc;
	double rbc;
	int hgb;
	int hct;
	int plt;
};

int cal(const Blood& b)
{
	int cnt = 0;
	if (b.wbc < 4.0 || b.wbc > 10.0) cnt++;
	if (b.rbc < 3.5 || b.rbc > 5.5) cnt++;
	if (b.plt < 100 || b.plt > 300) cnt++;
	if ("male" == b.sex)
	{
		if (b.hgb < 120 || b.hgb > 160) cnt++;
		if (b.hct < 42 || b.hct > 48) cnt++;
	}
	else
	{
		if (b.hgb < 110 || b.hgb > 150) cnt++;
		if (b.hct < 36 || b.hct > 40) cnt++;
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		Blood b;
		ss >> b.sex >> b.wbc >> b.rbc >> b.hgb >> b.hct >> b.plt;
		int cnt = cal(b);
		cout << ((cnt == 0)?"normal":to_string(cnt)) << endl;
	}
}