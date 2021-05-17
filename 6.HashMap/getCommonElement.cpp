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
    int n1,n2;
    cin>>n1;
    vector<int> a(n1);
    map<int,int> mpp;
    for(int i=0;i<n1;i++){
        cin>>a[i];
        if(mpp[a[i]]==0)
            mpp[a[i]]++;
    }

    cin>>n2;

    vector<int> b(n2);
    for(int i=0;i<n2;i++){
        cin>>b[i];
        if(mpp[b[i]]==1){
            cout<<b[i]<<endl;
            mpp[b[i]]++;
        }
        
    }



}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}