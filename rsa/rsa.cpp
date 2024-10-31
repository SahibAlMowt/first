#include "rsa.h"

std::vector<int> sam_input()
{
    std::string input;
    std::vector<int> input_vector;

    std::cin >> input;

    for(char digit: input)
    {
        if(digit >= '0' && digit <= '9')
        {
            input_vector.push_back(digit - '0');
        }
    }
    
    std::reverse(input_vector.begin(), input_vector.end());

    return input_vector;
}

void sam_print(const std::vector<int> &v)
{
    for(auto iter = v.rbegin(); iter != v.rend(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

std::vector<int> sam_mp(const std::vector<int> &first, const std::vector<int> &second)
{
    std::vector<int> mp_vector;

    mp_vector.resize(first.size() + second.size() + 1);

    for(size_t i = 0; i != first.size(); i++)
    {
        int transfer = 0;

        for(size_t j = 0; j != second.size(); j++)
        {
            int mp = first[i] * second [j] + mp_vector[i + j] + transfer;
            mp_vector[i + j] = mp % 10;
            transfer = mp / 10;
        }
        
        mp_vector[i + second.size()] += transfer;
    }

    while(mp_vector.back() == 0)
    {
        mp_vector.pop_back();
    }
   
    return mp_vector;
}

bool sam_gcd(const std::vector<int> &first, int e)
{
    int mod_gcd_int = sam_mod_int(first, e);
    
    int gcd_res = sam_evklid(mod_gcd_int, e);
    
    return gcd_res == 1;
}

int sam_mod_int(std::vector<int> first, int e)
{
	int mod = 0;
	
	std::reverse(first.begin(), first.end());
	
	for(int digit: first)
	{
		mod = (mod * 10 + digit) % e; 
	}
	
	return mod;
}

int sam_evklid(int a, int b)
{
	while(b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

std::vector<int> sam_encryption(const std::vector<int> &message, int e, const std::vector<int> &n)
{
    std::vector<int> c;

    c = sam_pow(message, e, n);

    return c;
}

std::vector<int> sam_decryption(const std::vector<int> &c, int &d, const std::vector<int> &n)
{
    std::vector<int> m;

    m = sam_pow(c, d, n);

    return m;
}

std::vector<int> sam_pow(const std::vector<int> &first, int e, const std::vector<int> &n) 
{
    std::vector<int> pow_vector = {1}; 
    std::vector<int> mod_vector = sam_mod(first, n); 

    while (e > 0) 
    {
        if (e % 2 == 1)
        {
            pow_vector = sam_mod(sam_mp(pow_vector, mod_vector), n); 
		}

        mod_vector = sam_mod(sam_mp(mod_vector, mod_vector), n); 
        e >>= 1;
    }

    return pow_vector;
}

std::vector<int> sam_mod(std::vector<int> first, std::vector<int> second)
{
    auto[chast, ostatok] = sam_divide(first, second);
    return ostatok;
}

std::pair<std::vector<int>, std::vector<int>> sam_divide(const std::vector<int> &first, const std::vector<int> &second) 
{
    std::vector<int> chast;
    std::vector<int> ostatok;
    

    for (int i = first.size() - 1; i >= 0; i--) 
    {
        ostatok.insert(ostatok.begin(), first[i]);

        while (ostatok.size() > 1 && ostatok.back() == 0)
        {
            ostatok.pop_back();
        } 
        
        int ch = 0;

        while (sam_compare(second, ostatok)) 
        {
            sam_subtract(ostatok, second);
            ch++;
        }
        chast.push_back(ch);
    }

    std::reverse(chast.begin(), chast.end());

    while (chast.size() > 1 && chast.back() == 0)
    {
        chast.pop_back();
    } 

    return {chast, ostatok};
}

bool sam_compare(const std::vector<int> &first, const std::vector<int> &second)
{
    if (first.size() != second.size())
    {
        return first.size() < second.size();
    } 
    for (int i = first.size() - 1; i >= 0; i--) 
    {
        if (first[i] != second[i])
        {
            return first[i] < second[i];
        } 
    }
    return true;
}

void sam_subtract(std::vector<int> &first, const std::vector<int> &second)
{
    int t;
    t = 0;

    for(size_t i = 0; i < first.size(); i++)
    {
        int p;
        p = t;

        if(i < second.size())
        {
            p += second[i];
        }

        if(first[i] < p)
        {
            first[i] += 10;
            t = 1;
        }
        else
        {
            t = 0;
        }

        first[i] -= p;
    }

    while(first.back() == 0)
    {
        first.pop_back();
    }
}

//---------------------------------------------------------------------------------

std::vector<int> sam_division_int2(std::vector<int> first, int e)
{
    std::vector<int> divider_vector;

    std::reverse(first.begin(), first.end());

    int divider = 0;

    for (int digit : first)
    {
        divider = (divider * 10) + digit;

        int res = divider / e;

        divider_vector.push_back(res);

        divider %= e;
    }


    while (!divider_vector.empty() && divider_vector[0] == 0) 
    {
        divider_vector.erase(divider_vector.begin());
    }

    std::reverse(divider_vector.begin(), divider_vector.end());

    return divider_vector;
}

std::vector<int> sam_pow_vector(const std::vector<int> &first, std::vector<int> d, const std::vector<int> &n) 
{
    std::vector<int> pow_vector = {1}; 
    std::vector<int> mod_vector = sam_mod(first, n); 
    std::vector<int> two = {2};
    std::vector<int> nolik = {0};

    while (!sam_equal(nolik, d)) 
    {
        auto[chast, ostatok] = sam_divide(d, two);

        if (sam_equal({1}, ostatok))
        {
            pow_vector = sam_mod(sam_mp(pow_vector, mod_vector), n); 
		}

        mod_vector = sam_mod(sam_mp(mod_vector, mod_vector), n); 
        d = chast;
    }

    return pow_vector;
}

bool sam_equal(const std::vector<int> &first, const std::vector<int> &second)
{
    return first == second;
}

std::vector<int> sam_decryption_vector(const std::vector<int> &c, std::vector<int> &d, const std::vector<int> &n)
{
    std::vector<int> m;

    m = sam_pow_vector(c, d, n);

    return m;
}

std::vector<char> sam_input_char()
{
    std::string input;
    std::vector<char> input_vector;

    std::cin >> input;

    for(char symbol: input)
    {
        input_vector.push_back(symbol);
    }

    return input_vector;
}

std::pair<std::vector<int>, std::vector<int>> sam_encryption_char(const std::vector<char> &message, int e, const std::vector<int> &n)
{
    std::pair<std::vector<int>, std::vector<int>> result;
    
    std::vector<int> res;
    std::vector<int> count;
    
    for(char symbol: message)
    {
		int count_int = 0;
		int sym = symbol;
		std::cout << sym << "\n";

		while(sym > 0)
		{
			res.push_back(sym % 10);
			sym /= 10;
			count_int++;
		}

		count.push_back(count_int);
	}
	
	std::vector<int> res_pow;
	
	res_pow = sam_pow(res, e, n);
	
	std::cout << "res_pow\t";
	sam_print(res_pow);
		
	result.first = res_pow;
	result.second = count;    

    return result;
}

std::vector<int> sam_decryption_char(std::pair<std::vector<int>, std::vector<int>> &cmessage, std::vector<int> &d, const std::vector<int> &n)
{
    
    std::vector<int> res;
    
    std::string output;

    res = sam_pow_vector(cmessage.first, d, n);
    
    std::vector<int> t_int;
    t_int = res;
    
    std::reverse(cmessage.second.begin(), cmessage.second.end());
    
    for(size_t i = 0; i < cmessage.second.size(); i++)
    {
		int count;
		int count_erase;
		count = cmessage.second[i];
		count_erase = cmessage.second[i];
		
		int num = 0;
		for(auto iter = t_int.end() - 1; iter != t_int.begin() - 1; iter--)
		{
			num = (num * 10) + *iter;
			count--;
			if(count < 1)
			{
				break;
			}
		}
		
		t_int.erase(t_int.end() - count_erase, t_int.end());
		
		output += static_cast<char> (num);
	} 
	
	std::reverse(output.begin(), output.end());
	std::cout << "output\t" << output << "\n";

    return res;
}

