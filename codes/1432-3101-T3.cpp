#include<bits/stdc++.h>
using namespace std;
string key,plaintext;

void toLowerCase(string &str){
    for(int i=0;i<str.size();i++) str[i]=tolower(str[i]);
}

void removeSpaces(string &str){
    str.erase(remove(str.begin(),str.end(),' '),str.end());  
}

string generate_key(){
    int ps=plaintext.size();
    int i;
    for(i=0;;i++){
        if(i==key.size()) i=0;
        if(key.size()==plaintext.size()) break;
        else{
            key.push_back(key[i]);
        }
    }
    return key;
}

string generate_cyphertext(){
    string cypher_text;

    for(int i=0;i<plaintext.size();i++){
        int p=plaintext[i]-'a';
        int k=key[i]-'a';
        int c=(p+k)%26;
        char ch=(char)(c+'a');
        cypher_text.push_back(ch);
    }

    return cypher_text;
}

string decrypt_text(string cypherText){
    string original_text;

    for(int i=0;i<cypherText.size();i++){
        int c=cypherText[i]-'a';
        int k=key[i]-'a';
        int p=((c-k)+26)%26;

        char pc=(char)(p+'a');
        original_text.push_back(pc);
    }

    return original_text;
}

int main(){
    cout<<"Enter key:";
    cin>>key;
    toLowerCase(key);
    // cout<<key<<endl;
    cout<<"Enter plaintext:";
    cin.ignore();
    getline(cin,plaintext);

    removeSpaces(plaintext);
    toLowerCase(plaintext);

    string derived_key=generate_key();

    cout<<"Generated key:"<<derived_key<<endl;
    cout<<plaintext.size()<<endl;
    cout<<key.size()<<endl;

    string ect=generate_cyphertext();

    cout<<"Cypher text:"<<ect<<endl;

    string dct=decrypt_text(ect);

    cout<<"original text:"<<dct<<endl;


    
}