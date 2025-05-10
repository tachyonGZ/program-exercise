//问题描述
//
//一张CT扫描的灰度图像可以用一个N* N（0 < N < 100）的矩阵描述，矩阵上的每个点对应一个灰度值（整数），其取值范围是0～255。我们假设给定的图像中有且只有一个肿瘤。在图上监测肿瘤的方法如下：如果某个点对应的灰度值小于等于50，则这个点在肿瘤上，否则不在肿瘤上。我们把在肿瘤上的点的数目加起来，就得到了肿瘤在图上的面积。任何在肿瘤上的点，如果它是图像的边界或者它的上下左右四个相邻点中至少有一个是非肿瘤上的点，则该点称为肿瘤的边界点。肿瘤的边界点的个数称为肿瘤的周长。现在给定一个图像，要求计算其中的肿瘤的面积和周长。
//
//输入形式
//
//输入第一行包含一个正整数N（0 < N < 100），表示图像的大小；接下来N行，每行包含图像的一行。图像的一行用N个整数表示（所有整数大于等于0，小于等于255），两个整数之间用一个空格隔开。
//
//输出形式
//
//输出只有一行，该行包含两个正整数，分别为给定图像中肿瘤的面积和周长，用一个空格分开。
//
//样例输入
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
//样例输出
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