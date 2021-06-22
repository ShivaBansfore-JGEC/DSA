#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &a,int mn,int mx){
    int r=mx-mn+1;
    vector<int> fr(r,0);
    for(int i=0;i<a.size();i++){
        int idx=a[i]-mn;
        fr[idx]++;
    }

    for(int i=1;i<fr.size();i++){
        fr[i]=fr[i-1]+fr[i];
    }



    int ans[a.size()];

    for(int i=a.size()-1;i>=0;i--){
        int val=a[i];
        int pos=fr[val-mn];
        int idx=pos-1;
        ans[idx]=val;
        fr[val-mn]--;
    }

    for(int u:ans){
        cout<<u<<endl;
    }
    cout<<endl;

}

/*
    Time and space complexity of countsort is 
    time -> O(n+k);
    space -> O(n+k)

    where k is the range of input

 */


int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    

    countSort(a,mn,mx);




    return 0;
}