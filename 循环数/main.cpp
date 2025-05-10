/*
��������

n λ��һ��������ѭ������cyclic���������ǣ�����һ�� 1 �� n ֮�������ȥ����ʱ����õ�һ����ԭ��������β���ѭ���ƶ�������������ĳ���Ͽ����õ������֣������ֳ��ȴ���nλʱ��ȡ��nλ����Ҳ����˵�������ԭ�������ֺ��µ����ֶ���β��ӣ����ǵõ��Ļ�����ͬ�ġ�ֻ������������ʼ���ֲ�һ����ͬ�����磬���� 142857 ��ѭ��������Ϊ��

142857 *1 = 142857

142857 *2 = 285714

142857 *3 = 428571

142857 *4 = 571428

142857 *5 = 714285

142857 *6 = 857142

дһ������ȷ�����������Ƿ���ѭ������

������ʽ

�����һ��Ϊ������������n������n�г���Ϊ 2 λ�� 60 λ��������(ע�⣬�ȵ���0Ҳ�Ǻ�������벻Ӧ�ñ�����,���� "01"�� 2 λ����"1" �� 1 λ����)

�����ʽ

����ÿһ����������������һ�б������Ƿ���ѭ������

��������

5
142857
142856
142858
01
0588235294117647

�������

142857 is cyclic
142856 is not cyclic
142858 is not cyclic
01 is not cyclic
0588235294117647 is cyclic
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsCyclicNumber(string num)
{
	string dnum = num + num;
	for (size_t i = 2; i <= num.size(); i++)
	{
		string multi = to_string(stoll(num) * i);
		if (multi.size() > num.size()) multi = multi.substr(multi.size() - num.size());
		if (dnum.find(multi) == string::npos) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string num;
		cin >> num;
		if (IsCyclicNumber(num)) cout << num << " is cyclic" << endl;
		else cout << num << " is not cyclic" << endl;
	}
	
	return 0;
}