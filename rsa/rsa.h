#ifndef rsa_h
#define rsa_h

#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> sam_input();
void sam_print(const std::vector<int> &v);
std::vector<int> sam_mp(const std::vector<int> &first, const std::vector<int> &second);
bool sam_gcd(const std::vector<int> &first, int e);
int sam_mod_int(std::vector<int> first, int e);
int sam_evklid(int a, int b);
std::vector<int> sam_encryption(const std::vector<int> &message, int e, const std::vector<int> &n);
std::vector<int> sam_decryption(const std::vector<int> &c, int &d, const std::vector<int> &n);
std::vector<int> sam_pow(const std::vector<int> &first, int exp, const std::vector<int> &n);
std::vector<int> sam_mod(std::vector<int> first, std::vector<int> second);
std::pair<std::vector<int>, std::vector<int>> sam_divide(const std::vector<int> &first, const std::vector<int> &second);
bool sam_compare(const std::vector<int> &first, const std::vector<int> &second);
void sam_subtract(std::vector<int> &first, const std::vector<int> &second);

std::vector<int> sam_division_int2(std::vector<int> first, int e);
std::vector<int> sam_pow_vector(const std::vector<int> &first, std::vector<int> d, const std::vector<int> &n);
bool sam_equal(const std::vector<int> &first, const std::vector<int> &second);
std::vector<int> sam_decryption_vector(const std::vector<int> &c, std::vector<int> &d, const std::vector<int> &n);
std::vector<char> sam_input_char();
std::pair<std::vector<int>, std::vector<int>> sam_encryption_char(const std::vector<char> &message, int e, const std::vector<int> &n);
std::vector<int> sam_decryption_char(std::pair<std::vector<int>, std::vector<int>> &cmessage, std::vector<int> &d, const std::vector<int> &n);

#endif //rsa_h
