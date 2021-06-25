#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<=k;i++){
        pq.push(a[i]);
    }
    for(int i=k+1;i<n;i++){
        cout<<pq.top()<<endl;
        pq.pop();
        pq.push(a[i]);
    }

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}