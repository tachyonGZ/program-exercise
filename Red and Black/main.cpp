/*
问题描述

There is a rectangular room，covered with square tiles. Each tile is colored either red or black. A man is standing on a black tile. From a tile， he can move to one of four adjacent tiles. But he can't move on red tiles， he can move only on black tiles.

Write a program to count the number of black tiles which he can reach by repeating the moves described above.

输入形式

The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions， respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows.

'.' - a black tile

'#' - a red tile

'@' - a man on a black tile(appears exactly once in a data set)

The end of the input is indicated by a line consisting of two zeros.

输出形式

For each data set， your program should output a line which contains the number of tiles he can reach from the initial tile (including itself).

样例输入

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
0 0

样例输出

45
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(const vector<vector<char>> room, int sx, int sy)
{
	int w = room.size();
	int h = room[0].size();
	vector<vector<bool>> visited(w, vector<bool>(h, false));
	queue<pair<int, int>> q;
	
	q.push({sx, sy});
	visited[sx][sy] = true;
	int cnt = 1;

	while (!q.empty())
	{
		auto pos = q.front();
		int x = pos.first;
		int y = pos.second;
		q.pop();

		constexpr int directions[4][2] = {
			{1, 0}, {0, 1}, {-1, 0}, {0, -1}
		};

		for (const auto &dir : directions)
		{
			int nx = x + dir[0];
			int ny = y + dir[1];

			if (nx < 0 || nx >= w || ny < 0 || ny >= h)
				continue;

			if (room[nx][ny] != '.' || visited[nx][ny])
				continue;

			q.push({nx, ny});
			visited[nx][ny]=true;
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		vector<vector<char>> room(w, vector<char>(h));

		int sx = 0, sy = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> room[j][i];

				if (room[j][i] != '@')
					continue;

				sx = j;
				sy = i;
				room[j][i] = '.';
			}
		}

		int cnt = bfs(room, sx, sy);
		cout << cnt << endl;
	}
	return 0;
}