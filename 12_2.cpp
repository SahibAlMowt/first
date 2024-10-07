#include <iostream>
#include <set>
#include <string>

void function(std::set<std::string> &v, std::string &word)
{
    std::set<char> m;
    size_t j = 0;
    while(j < word.size())
    {
        int flag = 1;
        for(const auto &w: v)
        {      
            if(w.find(word[j]) == std::string::npos)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            m.insert(word[j]);
        }
        j++;
    }
    for(char element: m)
    {
        std::cout << element << " ";
    }
}

int main()
{
    std::set<std::string> v;
    std::string word;

    while(std::cin >> word)
    {   
        v.insert(word);
    }

    v.erase(word);

    function(v, word);

    return 0;
}