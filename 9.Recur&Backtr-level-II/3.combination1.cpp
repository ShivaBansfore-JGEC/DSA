#include<bits/stdc++.h>
using namespace std;

void combination(int cb,int ssf,int total_box,int ts,string asf){
    if(cb > total_box){
        if(ssf==ts){
            cout<<asf<<endl;
        }
        return;
    }
    combination(cb+1,ssf+1,total_box,ts,asf + "i");
    combination(cb+1,ssf,total_box,ts,asf + "-");
}


int main(){
    int noOfbox,items;
    cin>>noOfbox>>items;
    combination(1,0,noOfbox,items,"");
    return 0;
}