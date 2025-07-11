import std;

int euclideanGCD(int a, int b)
{
	if		(a == 0) return b;
	else if (b == 0) return a;
	else return euclideanGCD(b, a % b);
}

std::string mySubstr(std::string s, int offset, int max)
{ 
	std::string ns;
	char *p{ &(s[offset]) };

	for (int i = 0; i < max; ++i)
	{
		ns += *p;
		++p;
	}
	return ns;
}

std::string strGCD(std::string s1, std::string s2)
{
	if (s1 + s2 != s2 + s1) return "";
	else
	{
		int l1{ static_cast<int>(s1.size()) };
		int l2{ static_cast<int>(s2.size()) };

		//int lGCD{ std::gcd(l1, l2) };
		int lGCD{ euclideanGCD(l1, l2) };
		
		
		//return s1.substr(0, lGCD);
		return mySubstr(s1, 0, lGCD);
	}
}


int main()
{	
	std::cout << strGCD("ABABAB", "ABAB");
}