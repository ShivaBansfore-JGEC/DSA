#include<bits/stdc++.h>
using namespace std;

void permutationII(int cb,int tb,vector<int> items,int ts,int ssf,string asf){

    if(cb > tb){
        if(ssf==ts){
            cout<<asf<<endl;
        }
        return;
    }

    for(int i=0;i<items.size();i++){
        if(items[i]==0){
            items[i]=1;
            permutationII(cb+1,tb,items,ts,ssf+1,asf+to_string(i+1));
            items[i]=0;
        }
    }

     permutationII(cb+1,tb,items,ts,ssf,asf+"0");

}


int main(){
    int n,r;
    cin>>n>>r;
    vector<int> items(r,0);
    permutationII(1,n,items,r,0,"");


    return 0;
}