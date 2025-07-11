import std;

int main()
{
	std::vector<int> f1{ 1, 0, 0, 0, 1 };
	int newFlowers{ 0 };
	int dump{ 0 };

	int *mp{ &(f1[0]) };

	int *lp{ (mp == &(f1.front())) ? &dump : mp - 1 };
	int *rp{ (mp == &(f1.back())) ? &dump : mp + 1 };

	std::cout << lp << '\n'
		<< mp << '\n'
		<< rp << '\n';

	for (int i = 0; i < f1.size(); ++i)
	{
		for (int f : f1) std::cout << f;
		std::cout << '\n';

		mp = &(f1[i]);


		lp = (mp == &(f1.front())) ? &dump : mp - 1;
		rp = (mp == &(f1.back())) ? &dump : mp + 1;

		if ((*mp + *lp + *rp) == 0)
		{
			*mp = 1;
			newFlowers += 1;
		}
	}

	std::cout << newFlowers;
}
