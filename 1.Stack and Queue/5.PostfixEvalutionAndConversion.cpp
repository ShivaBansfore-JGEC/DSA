// Author : Shiva Bansfore
// College : Jalpaiguri Government Engineering College
// Address : Siliguri,West Bengal

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
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


void evaluation(stack<int> &st,char ch){
    int v1,v2;
    v2=st.top();
    st.pop();
    v1=st.top();
    st.pop();

    if(ch=='+'){
        st.push(v1+v2);
    }else if(ch=='-'){
        st.push(v1-v2);
    }else if(ch=='*'){
        st.push(v1*v2);
    }else{
        st.push(v1/v2);
    }
}


void infix(stack<string> &infx,char ch){
    
    string v1,v2;
    v1=infx.top();
    infx.pop();

    v2=infx.top();
    infx.pop();
    string chh(1,ch);

    string ans="("+v2+chh+v1+")";
    infx.push(ans);

}

void Prefix(stack<string> &pre,char ch){
    string v1,v2;
    v1=pre.top();
    pre.pop();

    v2=pre.top();
    pre.pop();
    string chh(1,ch);
    string ans=chh+v2+v1;
    pre.push(ans);

}

void solve(){

    string pf;
    cin>>pf;
    stack<int> eval;
    stack<string> infx,prefix;

    for(int i=0;i<pf.size();i++){
        if(isdigit(pf[i])){
            int v=pf[i]-'0';
            eval.push(v);
            infx.push(to_string(pf[i]-'0'));
            prefix.push(to_string(pf[i]-'0'));
        }else{
            evaluation(eval,pf[i]);
            infix(infx,pf[i]);
            Prefix(prefix,pf[i]);
        }
    }

    cout<<eval.top()<<endl;
    cout<<infx.top()<<endl;
   cout<<prefix.top()<<endl;


}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}