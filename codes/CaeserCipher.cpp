#include <iostream>
using namespace std;

string str;
int key;

void encryption() {
    for (int i = 0; i < str.size(); i++) {

            if (islower(str[i])) {
                str[i] =  toupper((str[i] - 'a' + key) % 26 +'a');
            } else if (isupper(str[i])) {
                str[i] = (str[i] - 'A' + key) % 26  +'A';
            }
       
    }
    cout << str << endl;
}

void decryption() {
    for (int i = 0; i < str.size(); i++) {
       
           
         str[i] = tolower( (str[i] - 'A' - key + 26) % 26 + 'A');
           
       
    }    cout << str << endl;
}

int main() {
    
    cout<<"Enter plain text:";
    cin >> str;
    cout<<"Enter Key to be shifted:";
    cin >> key;


    cout<<"Encrypted text:";
    encryption();
    cout<<"Decrypted text:";
    decryption();

    return 0;
}