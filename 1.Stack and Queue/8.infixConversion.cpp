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


int precedence(char ch){
    if(ch=='+' || ch== '-'){
        return 1;
    }else if(ch=='*' || ch=='/'){
        return 2;
    }
}

void solve(){
    string s;
    getline(cin,s);
    stack<string> prefix,postfix;
    stack<char> oprtr;

    for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(ch=='('){
            oprtr.push(ch);

        }else if(isalpha(ch)){
            prefix.push(string(1,ch));
            postfix.push(string(1,ch));

        }else if(ch==')'){
            while(oprtr.top()!='('){
                char op=oprtr.top();oprtr.pop();
                string v2=prefix.top();prefix.pop();
                string v1=prefix.top();prefix.pop();

                string opp(1,op);

                string ans=opp+v1+v2;
                prefix.push(ans);

                v2=postfix.top();postfix.pop();
                v1=postfix.top();postfix.pop();

                ans=v1+v2+opp;

                postfix.push(ans);   
            }
            oprtr.pop();

        }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            
            while(oprtr.size()>0 && oprtr.top()!='(' && precedence(ch)<=precedence(oprtr.top())){
                char op=oprtr.top();oprtr.pop();
                string v2=prefix.top();prefix.pop();
                string v1=prefix.top();prefix.pop();
                string opp(1,op);

                string ans=opp+v1+v2;

                prefix.push(ans);
                v2=postfix.top();postfix.pop();
                v1=postfix.top();postfix.pop();

                ans=v1+v2+opp;

                postfix.push(ans);
            }
            oprtr.push(ch);
        }
    }

    while(oprtr.size()!=0){
                char op=oprtr.top();oprtr.pop();
                string v2=prefix.top();prefix.pop();
                string v1=prefix.top();prefix.pop();

                string opp(1,op);

                string ans=opp+v1+v2;
                prefix.push(ans);
                v2=postfix.top();postfix.pop();
                v1=postfix.top();postfix.pop();

                ans=v1+v2+opp;

                postfix.push(ans);  
    }

    cout<<postfix.top()<<endl;
    cout<<prefix.top()<<endl;
}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}