#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int64;

int64 Bin_to_dec(string bin){

    int64 value=bitset<64>(bin).to_ullong();
    return value;
}

int main(){
    string temp;
    cout<<"Enter binary value:";
    cin>>temp;

    cout<<Bin_to_dec(temp)<<endl;

    return main();

}