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


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // int dp[2][n];

    // dp[0][0]=0;
    // dp[1][0]=a[0];

    // for(int i=1;i<n;i++){
    //     dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
    //     dp[1][i]=dp[0][i-1]+a[i];
    // }

    // // for(int i=0;i<2;i++){
    // //     for(int j=0;j<n;j++){
    // //         cout<<dp[i][j]<<" ";
    // //     }
    // //     cout<<endl;
    // // }

    // int ans=max(dp[0][n-1],dp[1][n-1]);
    // cout<<ans<<endl;

    int zero_val=0;
    int one_val=a[0];
    for(int i=1;i<n;i++){
        int curr_zeroVal=max(zero_val,one_val);
        int curr_one=zero_val+a[i];

        zero_val=curr_zeroVal;
        one_val=curr_one;
    }
    cout<<max(zero_val,one_val)<<endl;
}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}