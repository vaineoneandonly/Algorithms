import std;

template <typename... T>
void printPointers(T... p)
{
	((std::cout << "val: "		 << *p 
				<< "\naddress: " <<  p 
				<< '\n'), ...);

	std::cout << '\n';
}

template <typename T>
void myBinarySearch(std::vector<T> v, int target)
{
	int *l{ &(v.front()) };
	int *h{ &(v.back()) };
	int *m{ l + (h - l) / 2 };

	int passCount{ 0 };
	
	auto mbsPass = [v, target, &l, &h, &m, &passCount]()
	{
		if (target == *m)
		{
			std::cout
				<< "target "			<< target
				<< " found at address " << m
				<< " after "			<< passCount
				<< " steps."			<< '\n';

			return true;
		}
		else if (target > *m) l = m + 1;
		else if (target < *m) h = m - 1;

		m = l + (h - l) / 2;

		++passCount;
		printPointers(l, m, h);
		return false;
	};
	
	bool found;
	do { found = mbsPass(); } while (!found);
}

int main()
{
	std::vector<int> a1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	std::println();

	int *l{ &(a1.front()) };
	int *h{ &(a1.back()) };
	int *m{ l + (h - l) / 2 };

	//myBinarySearch(a1, 11);

	std::vector<int> v2{ 32, 39, 42, 47, 71, 74, 92, 95, 105, 109, 110, 116, 131, 134, 141, 145, 149, 158, 161, 176, 190, 195, 207, 208, 234, 240, 260, 270, 273, 296, 303, 307, 313, 326, 340, 346, 356, 359, 364, 367, 380, 381, 382, 392, 399, 409, 427, 466, 468, 469, 486, 499, 507, 513, 515, 525, 531, 533, 548, 552, 560, 602, 620, 622, 638, 644, 649, 650, 659, 665, 680, 690, 699, 712, 715, 733, 739, 761, 775, 781, 787, 792, 804, 815, 830, 835, 848, 872, 884, 902, 905, 907, 933, 946, 957, 959, 961, 965, 969, 994
	};
	
	myBinarySearch(v2, 158);

	
}