import std;

bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
{
	int	  nf{ 0 };
	int dump{ 0 };

	for (int i = 0; i < flowerbed.size(); ++i)
	{
		int *mp{ &flowerbed[i] };
		int *lp{ mp == &flowerbed.front() ? &dump : mp - 1 };
		int *rp{ mp == &flowerbed.back()  ? &dump : mp + 1 };
	
		if ((*lp + *mp + *rp) == 0)
		{
			*mp = 1;
			++nf;
		}
	}

	return n <= nf;
}

int main()
{
	std::vector<int> f1{ 1, 0, 0, 0, 1 };
	std::cout << canPlaceFlowers(f1, 3);


}