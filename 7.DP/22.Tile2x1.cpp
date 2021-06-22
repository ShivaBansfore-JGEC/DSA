// Author : Shiva Bansfore
// College : Jalpaiguri Government Engineering College
// Address : Siliguri,West Bengal

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define all(a) a.begin(),a.end()
#define pie 3.1415926535898
#define mod (ll)(998244353)
#define MOD (int) 1e9+7
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define vi vector<int>
#define vii vector<vector<>> 
#define mp map<ll,ll> 
#define inf (ll)(1e18)
#define inff INT_MIN 
#define pb emplace_back
#define sz(s) s.size()
#define ff first
#define ss second
#define bits(n) __builtin_popcount(n)
#define rr return 0
#define ini(a, i) memset(a, i, sizeof(a))
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}



// int tile1(int n,vector<int> &dp){
//     if(n==1){
//         return 1;
//     }

//     if(n==2){
//         return 2;
//     }

//     if(dp[n]!=-1){
//         return dp[n];
//     }

//     return dp[n]=tile1(n-1,dp)+tile1(n-2,dp);
// }


void solve(){
    int n;
    cin>>n;
   vector<int> dp(n+1);
    //cout<<tile1(n,dp)<<endl;

    // dp[1]=1;
    // dp[2]=2;
    // for(int i=3;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }

    // cout<<dp[n]<<endl;

        int a=1;
        int b=2;
        
        for(int i=3;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
        }

        cout<<b<<endl;

}

int main(){
   fio;
   int t=1;
  // cin>>t;
   while(t--) solve();
return 0;
}