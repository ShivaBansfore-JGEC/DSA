#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int cost[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cost[i][j];
        }
    }

    int dp[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
        }
    }


    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j]=cost[i][j];
            }else{
                if(i==0){
                    dp[i][j]=cost[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
                }else if(i==n-1){
                    dp[i][j]=cost[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
                }else{
                    dp[i][j]=cost[i][j]+max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
                }
            }
        }
    }

    int ans=INT_MIN;

    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
    }

    cout<<ans<<endl;

    
    return 0;
}