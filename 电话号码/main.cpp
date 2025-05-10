/*
��������

��ҵϲ�������ױ���ס�ĵ绰���롣�õ绰�������ױ���ס��һ���취�ǽ���д��һ�����׼�ס�ĵ��ʻ��߶�����磬����Ҫ������¬��ѧ��绰ʱ�����Բ���TUT-GLOP����ʱ��ֻ���绰�����в�������ƴд�ɵ��ʡ��������ϻص��Ƶ꣬����ͨ������310-GINO����Gino's��һ��pizza���õ绰�������ױ���ס����һ���취����һ�ֺüǵķ�ʽ�Ժ�������ֽ��з��顣ͨ�������ʤ�͵�"����ʮ";����3-10-10-10������Դ��������ﶩpizza��

�绰����ı�׼��ʽ����λʮ�����������ڵ���������λ����֮����һ�����ӷ����绰�������ṩ�˴���ĸ�����ֵ�ӳ�䣬ӳ���ϵ���£�

A�� B����C ӳ�䵽 2

D�� E����F ӳ�䵽 3

G�� H����I ӳ�䵽 4

J�� K����L ӳ�䵽 5

M�� N����O ӳ�䵽 6

P�� R����S ӳ�䵽 7

T�� U����V ӳ�䵽 8

W�� X����Y ӳ�䵽 9

Q��Zû��ӳ�䵽�κ����֣����ַ�����Ҫ���ţ�����������Ӻ�ɾ���� TUT-GLOP�ı�׼��ʽ��888-4567��310-GINO�ı�׼��ʽ��310-4466��3-10-10-10�ı�׼��ʽ��310-1010��

���������������ͬ�ı�׼��ʽ����ô���Ǿ��ǵ�ͬ�ģ���ͬ�Ĳ��ţ�

��Ĺ�˾����Ϊ���صĹ�˾��дһ���绰���뱡����Ϊ�������Ƶ�һ���֣�����Ҫ����Ƿ��������Ͷ����˾ӵ����ͬ�ĵ绰���롣

������ʽ

����ĸ�ʽ�ǣ���һ����һ����������ָ���绰���뱡�к�������������10000�������µ�ÿ����һ���绰���롣ÿ���绰���������֣���д��ĸ������Q��Z���Լ����ӷ���ɡ�ÿ���绰������ֻ��պ���7�����ֻ�����ĸ��

�����ʽ

����ÿ�������ظ��ĺ������һ�����������Ǻ���ı�׼��ʽ����һ���ո�Ȼ���������ظ�������������ڶ���ظ��ĺ��룬���պ�����ֵ�����������������������û���ظ��ĺ��룬���һ�У�

No duplicates.

��������

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

�������

310-1010 2
487-3279 4
888-4567 3
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

char ToDigit(char c) {
	if (c >= 'A' && c <= 'C') return '2';
	if (c >= 'D' && c <= 'F') return '3';
	if (c >= 'G' && c <= 'I') return '4';
	if (c >= 'J' && c <= 'L') return '5';
	if (c >= 'M' && c <= 'O') return '6';
	if (c >= 'P' && c <= 'S') return '7';
	if (c >= 'T' && c <= 'V') return '8';
	if (c >= 'W' && c <= 'Y') return '9';
	return c;
}

string normalize(const string &phone)
{
	string normal = "";
	for (char c : phone) if (c != '-') normal += ToDigit(c);
	normal.insert(3, "-");
	return normal;
}

int main()
{
	int n;
	cin >> n;
	unordered_map<string, int> phones;
	vector<string> duplicate;
	for (int i = 0; i < n; i++)
	{
		string phone;
		cin >> phone;
		phone = normalize(phone);
		phones[phone]++;
	}
	for (const auto &phone : phones)
	{
		if (phone.second > 1)
			duplicate.push_back(phone.first + " " + to_string(phone.second));
	}
	if (duplicate.empty()) cout << "No duplicates." << endl;
	else
	{
		sort(duplicate.begin(), duplicate.end());
		copy(duplicate.begin(), duplicate.end(), ostream_iterator<string>(cout, "\n"));
	}
	return 0;
}