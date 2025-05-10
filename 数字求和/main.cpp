#include <iostream>

int main() {
	int a;
	std::cin >> a;
	
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int n;
		std::cin >> n;
		if (n <	a)
		{
			sum += n;
		}
	}

	std::cout << sum;

	return 0;
}