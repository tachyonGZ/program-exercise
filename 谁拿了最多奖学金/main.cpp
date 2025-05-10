/*
��������

ĳУ�Ĺ�������ÿѧ�ڵ���ĩ����֮�󷢷Ž�ѧ�𡣷��ŵĽ�ѧ�������֣���ȡ���������Բ�ͬ��

1) Ժʿ��ѧ��ÿ��8000Ԫ����ĩƽ���ɼ�����80�֣�>80���������ڱ�ѧ���ڷ���1ƪ��1ƪ�������ĵ�ѧ�����ɻ�ã�

2) ���Ľ�ѧ��ÿ��4000Ԫ����ĩƽ���ɼ�����85�֣�>85�������Ұ༶����ɼ�����80�֣�>80����ѧ�����ɻ�ã�

3) �ɼ����㽱��ÿ��2000Ԫ����ĩƽ���ɼ�����90�֣�>90����ѧ�����ɻ�ã�

4) ������ѧ��ÿ��1000Ԫ����ĩƽ���ɼ�����85�֣�>85��������ʡ��ѧ�����ɻ�ã�

5) �༶���׽���ÿ��850Ԫ���༶����ɼ�����80�֣�>80����ѧ���ɲ����ɻ�ã�

ֻҪ���������Ϳ��Եý���ÿ�ѧ��Ļ�����û�����ƣ�ÿ��ѧ��Ҳ����ͬʱ��ö��ѧ������Ҧ�ֵ���ĩƽ���ɼ���87�֣��༶����ɼ�82�֣�ͬʱ������һλѧ���ɲ�����ô������ͬʱ������Ľ�ѧ��Ͱ༶���׽�������������4850Ԫ��

���ڸ�������ѧ����������ݣ��������Щͬѧ��õĽ���������ߣ���������ͬѧ�������ý�ѧ�����������

������ʽ

����ĵ�һ����һ������N��1 <= N <= 100������ʾѧ������������������N��ÿ����һλѧ�������ݣ�����������������������ĩƽ���ɼ����༶����ɼ����Ƿ���ѧ���ɲ����Ƿ�������ʡ��ѧ�����Լ���������������������ɴ�СдӢ����ĸ��ɵĳ��Ȳ�����20���ַ����������ո񣩣���ĩƽ���ɼ��Ͱ༶����ɼ�����0��100֮�������������0��100�����Ƿ���ѧ���ɲ����Ƿ�������ʡ��ѧ���ֱ���һ���ַ���ʾ��Y��ʾ�ǣ�N��ʾ���ǣ��������������0��10������������0��10����ÿ��������������֮����һ���ո�ָ���

�����ʽ

����������У���һ���ǻ����ཱ���ѧ�����������ڶ���������ѧ����õĽ����������������λ����λ���ϵ�ѧ����õĽ�����࣬�������֮���������ļ��г��������ѧ��������������������N��ѧ����õĽ�ѧ���������

��������

4
YaoLin 87 82 Y N 0
ChenRuiyi 88 78 N Y 1
LiXin 92 88 N N 0
ZhangQin 83 87 Y N 1

�������

ChenRuiyi
9000
28700
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student{
	string name;
	int average_score;
	int class_score;
	bool cadre;
	bool western;
	int paper;
	int total;
};

int cal(const Student &stu)
{
	int total = 0;
	if (stu.average_score > 80 && stu.paper >= 1)
	{
		total += 8000;
	}
	if (stu.average_score > 85 && stu.class_score > 80)
	{
		total += 4000;
	}
	if (stu.average_score > 90)
	{
		total += 2000;
	}
	if (stu.average_score > 85 && stu.western)
	{
		total += 1000;
	}
	if (stu.average_score > 80 && stu.cadre)
	{
		total += 850;
	}
	return total;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<Student> stus(n);
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);

		ss >> stus[i].name >> stus[i].average_score >> stus[i].class_score;

		char cadre, western;

		ss >> cadre >> western >> stus[i].paper;

		stus[i].cadre = 'Y' == cadre;
		stus[i].western = 'Y' == western;
		stus[i].total = cal(stus[i]);
		total += stus[i].total;
	}
	string top;
	int max = 0;
	for (const auto &s: stus)
	{
		if(s.total > max)
		{
			max = s.total;
			top = s.name;
		}
	}
	cout << top << '\n'
		<< max << '\n'
		<< total << std::endl;
}