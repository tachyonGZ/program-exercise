/*
��������

һ��Extense��ɭ����̽�յ�ʱ��С��������һ���Թ����Թ����Կ�������n * n�ĸ����ɣ�ÿ�����ֻ��2��״̬��.��#��ǰ�߱�ʾ����ͨ�У����߱�ʾ����ͨ�С�ͬʱ��Extense����ĳ�����ʱ����ֻ���ƶ�����������(����˵��������)�ĸ�����֮һ�����ڸ���ϣ�Extense��Ҫ�ӵ�A�ߵ���B�����ڲ��߳��Թ���������ܲ��ܰ쵽������������յ���һ������ͨ��(Ϊ#)���򿴳��޷��쵽��

������ʽ

��1���ǲ������ݵ�����k���������k�����롣ÿ��������ݵĵ�1����һ��������n (1 <= n <= 100)����ʾ�Թ��Ĺ�ģ��n * n�ġ���������һ��n * n�ľ��󣬾����е�Ԫ��Ϊ.����#���ٽ�����һ����4������ha�� la�� hb�� lb������A���ڵ�ha�У���la�У�B���ڵ�hb�У���lb�С�ע�⵽ha�� la�� hb�� lbȫ���Ǵ�0��ʼ�����ġ�

�����ʽ

k�У�ÿ�������Ӧһ�����롣�ܰ쵽�����"YES"���������"NO"��

��������

2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0

�������

YES
NO
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool CanReach(const vector<vector<char>> &maze, int ha, int la, int hb, int lb)
{
	vector<vector<bool>> visited(maze.size(), vector<bool>(maze.size(), false));
	queue<pair<int, int>> q;
	if (maze[ha][la] != '.')
	{
		return false;
	}
	q.push({ha, la});
	visited[ha][la] = true;

	while (!q.empty())
	{
		auto pos = q.front();
		q.pop();
		int h = pos.first, l = pos.second;

		if (h == hb && l == lb)
		{
			return true;
		}

		constexpr int directions[4][2] = {
			{1, 0}, {0, 1}, {-1, 0}, {0, -1}
		};

		for (const auto &dir : directions)
		{
			size_t nh = h + dir[0];
			size_t nl = l + dir[1];

			if (nh < 0 || nh >= maze.size() || nl < 0 || nl >= maze.size())
				continue;

			if (maze[nh][nl] != '.' || visited[nh][nl])
				continue;

			visited[nh][nl] = true;
			q.push({ nh, nl });
		}
	}

	return false;
}

int main()
{
	int k;
	cin >> k;

	while(k--)
	{
		int n;
		cin >> n;
		vector<vector<char>> maze(n, vector<char>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> maze[i][j];
			}
		}

		int ha, la, hb, lb;
		cin >> ha >> la >> hb >> lb;

		if (CanReach(maze, ha, la, hb, lb))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}