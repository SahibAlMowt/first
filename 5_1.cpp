#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	std::vector<std::vector<int>> new_matrix(n, std::vector<int> (m));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			new_matrix[i][j] = matrix[j][i];
		}
	} 
		
	return new_matrix;
}

void print(const std::vector<std::vector<int>> &matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}
	

int main()
{
	int m;
	int n;
	std::cin >> m;
	std::cin >> n;
	std::vector<std::vector<int>> matrix(m, std::vector<int> (n));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix[i][j] = i + j;
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	std::vector<std::vector<int>> transposed_matrix(n, std::vector<int> (m));
	transposed_matrix = transpose(matrix);
	
	std::cout << "\n\n";
	
	print(transposed_matrix);
	
	return 0;
}
