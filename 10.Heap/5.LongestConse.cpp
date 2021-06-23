#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,bool> mpp,mpp2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp2[a[i]]=true;
    }

    for(int u:a){
        mpp[u]=true;
    }

    for(int u:a){
        if(mpp[u-1]==true){
            mpp[u]=false;
        }
    }

    int len=0;
    int sp=0;

    for(int u:a){
        if(mpp[u]==true){
            int t=1;
            while(mpp2[u+t]==true){
                t++;
            }
            if(t > len){
                sp=u;
                len=t;
            }

        }
    }

    for(int i=0;i<len;i++){
        cout<<sp+i<<endl;
    }


    return 0;
}