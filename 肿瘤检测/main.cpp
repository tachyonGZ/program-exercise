//��������
//
//һ��CTɨ��ĻҶ�ͼ�������һ��N* N��0 < N < 100���ľ��������������ϵ�ÿ�����Ӧһ���Ҷ�ֵ������������ȡֵ��Χ��0��255�����Ǽ��������ͼ��������ֻ��һ����������ͼ�ϼ�������ķ������£����ĳ�����Ӧ�ĻҶ�ֵС�ڵ���50����������������ϣ������������ϡ����ǰ��������ϵĵ����Ŀ���������͵õ���������ͼ�ϵ�������κ��������ϵĵ㣬�������ͼ��ı߽�����������������ĸ����ڵ���������һ���Ƿ������ϵĵ㣬��õ��Ϊ�����ı߽�㡣�����ı߽��ĸ�����Ϊ�������ܳ������ڸ���һ��ͼ��Ҫ��������е�������������ܳ���
//
//������ʽ
//
//�����һ�а���һ��������N��0 < N < 100������ʾͼ��Ĵ�С��������N�У�ÿ�а���ͼ���һ�С�ͼ���һ����N��������ʾ�������������ڵ���0��С�ڵ���255������������֮����һ���ո������
//
//�����ʽ
//
//���ֻ��һ�У����а����������������ֱ�Ϊ����ͼ����������������ܳ�����һ���ո�ֿ���
//
//��������
//
//6
//
//99 99 99 99 99 99
//
//99 99 99 50 99 99
//
//99 99 49 49 50 51
//
//99 50 20 25 52 99
//
//40 50 99 99 99 99
//
//99 99 99 99 99 99
//
//�������
//
//9 8

#include <iostream>
#include <vector>

const int direction[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

bool IsInBounds(int x, int y, int n)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, std::vector<std::vector<int>> &image, std::vector<std::vector<bool>> &visited, int &area, int &perimeter)
{
	visited[x][y] = true;
	area++;
	bool is_boundary = false;
	for (const auto &dir : direction)
	{
		int nx = x + dir[0];
		int ny = y + dir[1];
		if(!IsInBounds(nx, ny, image.size()) || image[nx][ny] > 50)
		{
			is_boundary = true;
			continue;
		}
		else if(visited[nx][ny]) continue;
		dfs(nx, ny, image, visited, area, perimeter);
	}
	if (is_boundary) perimeter++;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> image(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> image[i][j];
		}
	}
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
	int area = 0, perimeter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (image[i][j] > 50 || visited[i][j]) continue;

			dfs(i, j, image, visited, area, perimeter);
		}
	}
	std::cout << area << " " << perimeter << std::endl;
	return 0;
}