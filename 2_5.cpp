#include <iostream>
#include <vector>
#include <string>

int max_index(std::vector<std::string> names)
{
	int lengths;
	int max_lengths = 0;
	size_t index = 0;
	while(index < names.size())
	{
		lengths = names[index].size();
		if(max_lengths < lengths)
		{
			max_lengths = lengths;
		}
		index++;
	}
	return max_lengths;
}

std::string LCP(std::vector<std::string> names)
{	
	int j = 0;
	std::string cstr;
	int max_j = max_index(names);
	while(j < max_j)
	{
		for(size_t i = 0; i < names.size() - 1; i++)
		{	
			if(names[i+1][j] == '\0')
			{
				return cstr;
			}
			if(names[i][j] != names[i+1][j])
			{
				return cstr;
			}	
		}
		cstr += names[0][j];
		j++;
	}
	return cstr;
}

int main()
{
	std::string str;
	std::vector<std::string> names;
	
	while(std::getline(std::cin, str))
	{
		names.push_back(str);
	}
	
	str = LCP(names);
	std::cout << str;
	
	return 0;
}
