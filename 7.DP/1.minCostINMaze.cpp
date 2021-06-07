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


    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=cost[i][j];
            }else{
                if(i==n-1){
                    dp[i][j]=cost[i][j]+dp[i][j+1];
                }else if(j==m-1){
                    dp[i][j]=cost[i][j]+dp[i+1][j];
                }else{
                    dp[i][j]=cost[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
    }

    cout<<dp[0][0]<<endl;

    
    return 0;
}