#include<bits/stdc++.h>
using namespace std;

int dp[20][11];

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

    for(int i=0;i<=n;i++){
        for(int c=0;c<=cap;c++){
            if(i==0 || c==0){
                dp[i][c]=0;
            }else{
                if(c-wt[i-1]>=0){
                    int value=max(val[i-1]+dp[i-1][c-wt[i-1]],dp[i-1][c]);
                    dp[i][c]=value;
                }else{
                    dp[i][c]=dp[i-1][c];
                }
            }
        }
    }


    cout<<dp[n][cap]<<endl;

    
    return 0;
}