#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>

std::string f(std::string word)
{
	size_t j = 0;
	while(j < word.size())
	{
		if(word[j] < 47 && word[j] > 33)
		{
			word.erase(j);
			return word;
		}
		j++;
	}
	
	return word;
}	

int main()
{
	
	std::ifstream finl("love.txt");
	std::unordered_set<std::string> love_set;
	std::string lword;
	while(finl >> lword)
	{
		love_set.insert(lword);
	}
	
	std::map<std::string, int> s;
	std::string word;
	
	std::ifstream fins("123.txt");

	while(fins >> word)
	{
		if(love_set.contains(f(word)))
		{
			++s[f(word)];
		}
	}
	
	for(const auto &[word, count]: s)
	{
		std::cout << word << "\t" << count << "\n";
	}
	
	finl.close();
	fins.close();
	
	return 0;
}