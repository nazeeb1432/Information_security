#include<bits/stdc++.h>
using namespace std;

string s1024;

void preprocessing(string myString){
    stringstream fixedstream;
 //FILE *Fp 
   
    for (int i = 0;
         i < myString.size(); ++i) {
 
       
        fixedstream << bitset<8>(myString[i]);
    }

 // abc 
   
    string s1024;
 
    s1024 = fixedstream.str(); 
   // cout<<s1024<<endl;//added

   cout<<"string before padding(in bits):"<<endl;
   cout<<s1024<<endl;
   cout<<"string size: "<<s1024.size()<<endl;

 
  
    int orilen = s1024.length();
    int tobeadded;
 
   
    int modded = s1024.length() % 1024;
 
  
    if (1024 - modded >= 128) { //when msg size < 1024b
        tobeadded = 1024 - modded;
    }
 
 
    else if (1024 - modded < 128) { //when msg size is > 1024b
        tobeadded = 2048 - modded;
    }
 
 
    s1024 += "1";
 
   
    for (int y = 0; y < tobeadded - 129; y++) {
        s1024 += "0";
    }

    int temp=(tobeadded-129)+1;
 
  
    string lengthbits
        = std::bitset<128>(orilen).to_string();
 
 
    s1024 += lengthbits;
 
   
    int blocksnumber = s1024.length() / 1024;

    cout<<"string after padding(in bits):"<<endl;
   cout<<s1024<<endl;
   cout<<"padded lenght:"<<temp<<endl;
   cout<<"string size: "<<s1024.size()<<endl;
   cout<<"blocksnumber: "<<blocksnumber<<endl;
}

int main(){
    string mystring="IIT";
    preprocessing(mystring);

}