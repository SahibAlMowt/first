#include <iostream>
#include <vector>

bool self_dual_function(const std::vector<bool> &array);
bool linear_function(const std::vector<bool> &array);
bool monotonic_function(const std::vector<bool> &array);

int main()
{
	std::cout << "Enter the number of variables: \n"; 
	int n;
	std::cin >> n;
	int size = 1 << n;
	std::vector<bool> array(size);
	
	int x;
	for(int i = 0; i < size; i++)
	{
		std::cin >> x;
		array[i] = x;
	}
	
	if(!array[0])
	{
		std::cout << "function ~ T0\n";
	}
	
	if(array[size - 1])
	{
		std::cout << "function ~ T1\n";
	}
	
	if(self_dual_function(array))
	{
		std::cout << "function ~ S\n";
	}
	
	if(linear_function(array))
	{
		std::cout << "function ~ L\n";
	}
	
	if(monotonic_function(array))
	{
		std::cout << "function ~ M\n";
	}
	
	std::cout << "Truth table:\n";
	
	for(int i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
	
	return 0;
}

bool self_dual_function(const std::vector<bool> &array)
{	
	int size = array.size();
	for(int i = 0; i <= (size - 1) / 2; i++)
	{
		if(array[i] == array[size - i - 1])
		{
			return false;
		}
	}
	
	return true;
}


bool monotonic_function(const std::vector<bool> &array)
{
	int size = array.size();
	for(int i = 0; i < size - 1; i++)
	{
		int j = i + 1;
		while(j < size)
		{
			if(array[0] > array[j])
			{
				return false;
			}
			
			if((i & j) != 0)
			{
				if(array[i] > array[j])
				{
					return false;
				}
			}
			j++;
		}
		
	}
	
	return true;
}

bool linear_function(const std::vector<bool> &array)
{
	int size = array.size();
	std::vector<bool> c(size);
	
	c[0] = array[0];
	
	for(int i = 1; i < size; i++)
	{
		if((i & (i - 1)) == 0)
		{
			c[i] = array[i] != c[0];
		}
		else
		{
			int equals = 0;
			for(int r = 0; r <= i; r++)
			{
				equals = array[i];
				if(i & (1 << r))
				{
					equals -= array[i ^ (1 << r)];
				}
			}
			c[i] = equals;
		}
	}
	
	for(int i = 1; i < size; i++)
	{		
		if((i & (i - 1)) != 0)
		{
			if(c[i] != 0)
			{
				return false;
			}
		}
	}
	
	return true;
	
}
