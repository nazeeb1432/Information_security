#include "mix.hpp"

#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned char state_arr[]="satishcjisboring";
    mixColumn(state_arr);
    unsigned char after_mix_column[16];

    for(int i=0;i<16;i++) after_mix_column[i]=state_arr[i];

    for(int j=0;j<16;j++){
        if(j%4 ==0 and j!=0) cout<<"\n";
        printf("%02X ",after_mix_column[j]);
    }
    cout<<endl;

    return 0;

}
