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


int precedence(char ch){
    if(ch=='+'){
        return 1;
    }else if(ch=='-'){
        return 1;
    }else if(ch=='*'){
        return 2;
    }else{
        return 2;
    }
}

int operation(int v1,int v2,char ch){
    if(ch=='+'){
        return v1+v2;
    }else if(ch=='-'){
        return v1-v2;
    }else if(ch=='*'){
        return v1*v2;
    }else{
        return v1/v2;
    }
}


void solve(){
    string s;
    getline(cin,s);


    stack<int> opnd;
    stack<char> oprtr;
    for(int i=0;i<s.size();i++){

        if(s[i]=='('){
            oprtr.push(s[i]);
        }else if(isdigit(s[i])){
            opnd.push(s[i]-'0');
        }else if(s[i]==')'){
            while(oprtr.top()!='('){
                char op=oprtr.top();oprtr.pop();
                int v2=opnd.top();opnd.pop();
                int v1=opnd.top();opnd.pop();
                int val=operation(v1,v2,op);
                opnd.push(val);
            }
            oprtr.pop();

        }else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            while(oprtr.size()>0 && oprtr.top()!='(' && precedence(s[i])<=precedence(oprtr.top())){
                char op=oprtr.top();oprtr.pop();
                int v2=opnd.top();opnd.pop();
                int v1=opnd.top();opnd.pop();
                int val=operation(v1,v2,op);
                opnd.push(val);
            }
            oprtr.push(s[i]);

        }else{
            continue;
        }
    }


        while(oprtr.size()!=0){
                char op=oprtr.top();oprtr.pop();
                int v2=opnd.top();opnd.pop();
                int v1=opnd.top();opnd.pop();
                int val=operation(v1,v2,op);
                opnd.push(val);
        }
        cout<<opnd.top()<<endl;
}

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}