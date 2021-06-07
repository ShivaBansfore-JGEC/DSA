#include<bits/stdc++.h>
using namespace std;


int dp[11];
int main(){
    int n;
    cin>>n;

    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    int cap;
    cin>>cap;
    

    for(int i=0;i<n;i++){
        int wgt=wt[i];
        for(int j=wt[i];j<=cap;j++){
            dp[j]=max(dp[j],val[i]+dp[j-wgt]);
        }
    }

    cout<<dp[cap]<<endl;

    return 0;
}