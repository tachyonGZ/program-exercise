/*问题描述
               7

            3     8

        8      1      0

    2     7      4       4

4     5      2      6       5
图中给出了一个数字三角形。从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。

注意：路径上的每一步只能从一个数走到下一层上和它最近的左边的那个数或者右边的那个数。

输入形式

输入的是一行是一个整数N (1 < N <= 100)，给出三角形的行数。下面的N行给出数字三角形。数字三角形上的数的范围都在0和100之间。

输出形式

输出最大的和。

样例输入

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

样例输出

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