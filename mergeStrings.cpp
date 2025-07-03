import std;

std::string mergeAlternately(std::string word1, std::string word2)
{
    bool dl{ word1.size() != word2.size() ? true : false };

    char *p1{ &(word1[0]) };
    char *p2{ &(word2[0]) };

    std::string w3{};

    while (*p1 != '\0' && *p2 != '\0')
    {
        w3 += *p1;
        w3 += *p2;

        ++p1;
        ++p2;
    }

    if (dl)
    {
        if (word1.size() > word2.size()) w3 += p1;
        else w3 += p2;
    }

    return w3;
}

int main()
{
	std::string w1{ "abcd" };
	std::string w2{ "pq" };

	bool dl{ w1.size() != w2.size() ? true : false };

	char *p1{ &(w1[0]) };
	char *p2{ &(w2[0]) };

	std::string w3{};

	while (*p1 != '\0' && *p2 != '\0')
	{
		w3 += *p1;
		w3 += *p2;

		++p1;
		++p2;
	}

	if (dl)
	{
		if (w1.size() > w2.size()) w3 += p1;
		else w3 += p2;
	}

	std::cout << mergeAlternately("abcd", "pq");
}
