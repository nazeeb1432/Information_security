// #include "aes.hpp"
#include "aesCbc.hpp"
// #include "aesCounter.hpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string inpt, encr;
    cout << "Input : ";
    getline(cin, inpt);
    encr = cbc_encryption(inpt);
    write_file(encr);
    string decr;
    decr = read_file();
    getDecryptedText(decr);
}