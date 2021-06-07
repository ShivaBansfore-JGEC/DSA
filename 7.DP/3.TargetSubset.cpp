#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int tar;
    cin>>tar;

    bool dp[n+1][tar+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(i==0 && j==0){
                dp[i][j]=true;
            }else if(i==0){
                dp[i][j]=false;
            }else if(j==0){
                dp[i][j]=true;
            }else{
                int coin=arr[i-1];
                bool exc=dp[i-1][j];
                bool inc=(j-coin >=0) ? dp[i-1][j-coin]:false;
                dp[i][j]=inc || exc;
            }
        }
    }

    if(dp[n][tar]==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }


    return 0;
}