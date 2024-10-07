#include <iostream>
#include <deque>
#include <string>

void doTrain(int number, std::deque<int> &v, std::string word)
{
	if(word == "+l")
	{
		v.push_front(number);
	}
	else if(word == "+r")
	{
		v.push_back(number);
	}
	else if(word == "-l")
	{
		int size = v.size();
		if(number > size)
		{
			v.clear();
			return;
		}
		auto iter1 = v.begin();
		auto iter2 = v.begin() + number;
		
		v.erase(iter1, iter2);
	}
	else if(word == "-r")
	{	
		int size = v.size();
		if(number > size)
		{
			v.clear();
			return;
		}
		auto iter1 = v.end() - number;
		auto iter2 = v.end();
		
		v.erase(iter1, iter2);
	}
}

int main()
{
	std::deque<int> v;
	std::string word;
	int number;
	
	while(std::cin >> word >> number)
	{
		doTrain(number, v, word);
	}
	
	for(int element: v)
	{
		std::cout << element << " ";
	}
		
	return 0;
}