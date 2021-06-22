#include<bits/stdc++.h>
using namespace std;


int findPivot(vector<int> a,int n){
    
    int lo=0,hi=n-1;

    while(lo < hi){
        int mid=(lo+hi) / 2;
        if(a[mid] < a[hi]){
            hi=mid;
        }else{
            lo=mid+1;
        }

    }

    return a[hi];
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<findPivot(a,n)<<endl;
    return 0;
}