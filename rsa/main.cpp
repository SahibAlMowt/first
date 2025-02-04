#include "rsa.h"

int main()
{
    std::vector<int> p;
    std::vector<int> q;

    std::cout << "p\t";
    p = sam_input();
    std::cout << "q\t";
    q = sam_input();

    std::vector<int> n;

    n = sam_mp(p, q);
   
    std::cout << "n\t";
    sam_print(n);

    p[0] -= 1;
    q[0] -= 1;

    std::cout << "p - 1\t";
    sam_print(p);

    std::cout << "q - 1\t";
    sam_print(q);

    std::vector<int> phi;

    phi = sam_mp(p, q);

    std::cout << "phi\t";
    sam_print(phi);

    int e = 2;

    do
    {   
        e -= 1;
        e = e << 1;
        e += 1;
      
    } while (!sam_gcd(phi,e));
    
    std::cout << "e\t" << e << "\n";

    std::vector<int> k;

    std::cout <<"k\t";
    k = sam_input();

    phi = sam_mp(phi, k);

    phi[0] += 1;
      
    std::vector<int> d;
    
    d = sam_division_int2(phi, e);

    std::cout << "d\t";
    sam_print(d);  

    std::vector<char> real_message;

    std::cout << "message\t";
    real_message = sam_input_char();

    std::pair<std::vector<int>, std::vector<int>> cf;
    cf = sam_encryption_char(real_message, e, n);

    std::vector<int> dc;

    dc = sam_decryption_char(cf, d, n);

    std::cout << "df\t";
    sam_print(dc);


    return 0;
    
    
}
