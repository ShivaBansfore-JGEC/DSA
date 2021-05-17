#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    map<char,int> mp;
    char ans;
    int mx=0;
    for(char u:s){
        mp[u]++;

        if(mx<mp[u]){
            mx=mp[u];
            ans=u;
        }
    }

    cout<<ans<<endl;
    return 0;
}