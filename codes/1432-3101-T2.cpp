#include<bits/stdc++.h>
using namespace std;
string key,plainText,cyphertext;
int idx[4];
// vector<vector<char>> grid;
char grid[5][5];

void preprocess(){
    int plaintext_size=plainText.size();
    if((plaintext_size%2)!=0){
        plainText+='x';
    }
}
void removeSpaces(string str){
    str.erase(remove(str.begin(),str.end(),' '),str.end());  
}

void toLowerCase(string str){
    for(int i=0;i<str.size();i++) str[i]=tolower(str[i]);
}

void generate_grid(){
    vector<bool> used(26,false);
    //hard code value for j
    used['j'-'a']=true;

    int i=0,j=0,k=0;
    //fill up the grid by key;
    for(k=0;k<key.size();k++){
        if(!used[key[k]-'a']){
            grid[i][j]=key[k];
            used[key[k]-'a']=true;
            j++;
        } 
        
        if(j==5){
            i++;
            j=0;
        }
    }
    //now fill the rest of the grid;
    for(k=0;k<26;k++){
        if(!used[k]){
            grid[i][j]=(char)(k+97);
            used[k]=true;
            j++;
        }
        
        if(j==5){
            i++;
            j=0;
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    
    

}
void search_in_grid(char a,char b){
    if(a=='j'){
        a='i';
    }
    else if(b=='j'){
        b='i';
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a==grid[i][j]){
                idx[0]=i;
                idx[1]=j;
            }
            else if(b==grid[i][j]){
                idx[2]=i;
                idx[3]=j;
            }
        }
    }
}

void encrypt_and_generate_cypher(){

    
    for(int i=0;i<plainText.size();i+=2){
        search_in_grid(plainText[i],plainText[i+1]);

        if(idx[0]==idx[2]){//if rows are the same,shift columns
            cyphertext+=grid[idx[0]][(idx[1]+1)%5];
            cyphertext+=grid[idx[0]][(idx[3]+1)%5];
            
        }
        else if(idx[1]==idx[3]){
            cyphertext+=grid[(idx[0]+1)%5][idx[1]];
            cyphertext+=grid[(idx[2]+1)%5][idx[1]];
        }
        else{
            cyphertext+=grid[idx[0]][idx[3]];
            cyphertext+=grid[idx[2]][idx[1]];
        }
    }
}

void playFairCypher(){

    toLowerCase(key);

    removeSpaces(plainText);
    toLowerCase(plainText);

    preprocess();
    generate_grid();

    encrypt_and_generate_cypher();
}


int main(){
    // grid.resize(5,vector<char>(5));

    cout<<"welcome to playFair cypher!"<<endl;
    cout<<"Enter key:";
    cin>>key;
    cout<<"Enter plain text:";
    cin.ignore();
    getline(cin,plainText);

    cout<<endl;

    playFairCypher();
    cout<<"CypherText: "<<cyphertext<<endl;


}