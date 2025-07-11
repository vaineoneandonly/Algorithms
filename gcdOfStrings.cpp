import std;

std::string gcdOfStrings(std::string str1, std::string str2)
{
	std::string res;

	if (str1 + str2 != str2 + str1) res = "";
	else
	{
		bool firstBigger{ (str1.size() > str2.size()) ? true : false };

		char *p{ (firstBigger) ? &(str1[str2.size()]) : &(str2[str1.size()]) };

		while (*p != '\0')
		{
			res += *p;
			++p;
		}
	}

	return res;
}

int main()
{
	std::string s{"ABC"};
	std::string t{"ABCABC"};
	std::string res;

	//bool secondBigger{ (t.size() > s.size()) ? true : false };
	bool firstBigger{ (s.size() > t.size()) ? true : false };

	char *p{&(s[0])};

	char *p2{ (firstBigger) ? &(s[0]) : &(t[0]) };

	if (s + t != t + s) res = "";
	else
	{
		//p += (secondBigger) ? t.size() : s.size();
		p2 += (firstBigger) ? t.size() : s.size();

		while (*p2 != '\0')
		{ 
			res += *p2;
			++p2;
		}

	}

	std::cout << '\n' << res << '\n';



	std::cout << gcdOfStrings("ABCABCABC", "ABC");

}