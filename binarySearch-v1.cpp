import std;

void printPointers(std::vector<int *> v) //alternativas pra isso? variádicas/templates/...
{
	for (int *p : v) std::cout << "val: " << *p << "\naddress: " << p << '\n';
	std::cout << '\n';
}

template <typename... T>
void varPP(T... p)
{
	((std::cout << "val: "		 << *p 
				<< "\naddress: " <<  p 
				<< '\n'), ...);

	std::cout << '\n';
}

int main()
{
	std::vector<int> a1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	std::println();

	int *l{ &(a1.front()) };
	int *m{ &(a1[a1.size() / 2]) };
	int *h{ &(a1.back()) };

	std::vector<int *> coords{ l, m, h };

	int t{ 5 };
	std::cout << "target: " << t << '\n';

	//printPointers({ l, m, h });
	varPP(l, m, h);

	if (t == *m) std::cout <<			   "target " << t 
						   << " found \nat address " << m 
						   <<	    "\nof position " << m - l << '\n';
	else if (t > *m)
	{
		l = m + 1;
		m = &(a1[(a1.size() / 2) + 2]);
	}
	else if (t < *m)
	{
		h = m - 1;
		m = &(a1[a1.size() / 4]);
	}

	//printPointers({ l, m, h });
	varPP(l, m, h);
}