// #include"aes_ecb.hpp"
// #include"aes_ctr.hpp"
#include"aes_cbc.hpp"
using namespace std;

int main()
{
    
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

    cout<<"Encryption and decryption complete!"<<endl;
}