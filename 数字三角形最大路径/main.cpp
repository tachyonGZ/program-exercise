/*��������
               7

            3     8

        8      1      0

    2     7      4       4

4     5      2      6       5
ͼ�и�����һ�����������Ρ��������εĶ������ײ��кܶ�����ͬ��·��������ÿ��·������·������������������Եõ�һ���ͣ������������ҵ����ĺ͡�

ע�⣺·���ϵ�ÿһ��ֻ�ܴ�һ�����ߵ���һ���Ϻ����������ߵ��Ǹ��������ұߵ��Ǹ�����

������ʽ

�������һ����һ������N (1 < N <= 100)�����������ε������������N�и������������Ρ������������ϵ����ķ�Χ����0��100֮�䡣

�����ʽ

������ĺ͡�

��������

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

�������

30
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    cout << triangle[0][0] << endl;
}