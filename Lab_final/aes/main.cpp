// #include"aes_ecb.hpp"
// #include"aes_ctr.hpp"
#include"aes_cbc.hpp"
using namespace std;

int main()
{
    // string inpt, encr ;
    // cout << "Input : " ;
    // getline( cin, inpt );
    // encr = cbc_encryption( inpt ) ;
    // write_file(encr);
    // string decr;
    //  decr= getDecryptedText( encr ) ;
    //  write_dec_file(decr, inpt.size());
    // cout<<decr<<endl;

    //answer if given file to read from

    ifstream fp;
    fp.open("input.txt");
    string plainText;
    string line;
    while(getline(fp,line)){
        plainText+=line;
        plainText+='\n';
    }
    // cout<<plainText<<endl;
    plainText.pop_back();

    string encryptedText=cbc_encryption(plainText);
    write_file(encryptedText);
    string decryptedText=getDecryptedText(encryptedText);
    write_dec_file(decryptedText,decryptedText.size());
}