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


struct st{
    int value,wt;
    double ratio;
};

bool compare(const st s1,const st s2){
    return s1.ratio > s2.ratio;
}

void solve(){
    int n;
    cin>>n;
    vector<int> value(n),wt(n);
    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    int cap;
    cin>>cap;

    vector<st> ratios(n);

    for(int i=0;i<n;i++){
        st stt;
        stt.value=value[i];
        stt.wt=wt[i];

        stt.ratio=(value[i] * 1.0 )/wt[i];
        ratios[i]=stt;
    }

    sort(all(ratios),compare);
    double ans=0.0;
    for(int i=0;i<n;i++){
        if(cap==0){
            break;
        }

        if(ratios[i].wt <= cap){
            ans+=(double)ratios[i].value;
            cap-=ratios[i].wt;
        }else{
            ans+=ratios[i].ratio*(1.0*cap);
            cap=0;
        }

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