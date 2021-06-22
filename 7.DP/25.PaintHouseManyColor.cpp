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
    int n,k;
    cin>>n>>k;

    int a[n][k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<k;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> dp(n,vector<int>(k));

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(i==0){
                dp[i][j]=a[i][j];
            }else{
                int mn=INT_MAX;
                for(int m=0;m<k;m++){
                    if(m!=j){
                        mn=min(mn,dp[i-1][m]);
                        //cout<<dp[i-1][k]<<endl;
                    }
                }
                dp[i][j]=mn+a[i][j];
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<k;i++){
        ans=min(ans,dp[n-1][i]);
    }

    cout<<ans<<endl;
}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}