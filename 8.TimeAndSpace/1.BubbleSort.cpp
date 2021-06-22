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


// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j) {
    cout<<("Swapping " + to_string(arr[i]) + " and " + to_string(arr[j]))<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

  // return true if ith element is smaller than jth element
   bool isSmaller(vector<int> &arr, int i, int j) {
    cout<<("Comparing " + to_string(arr[i]) + " and " + to_string(arr[j]))<<endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
  }


void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(isSmaller(a,j+1,j)){
                swap(a,j+1,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}


//time complexity of bubble sort is o(n^2)

int main(){
   fio;
   int t=1;
   //cin>>t;
   while(t--) solve();
return 0;
}