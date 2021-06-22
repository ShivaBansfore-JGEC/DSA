#include<bits/stdc++.h>
using namespace std;


void targe_sum_pair(vector<int> &a,int tar){
    sort(a.begin(),a.end());

    int l=0,r=a.size()-1;
    while(l<r){
        int sum=a[l]+a[r];
        if(sum < tar){
            l++;
        }else if(sum > tar){
            r--;
        }else{
            cout<<a[l]<<","<<a[r]<<endl;
            l++;
            r--;
        }
    }

}



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int tar;
    cin>>tar;
    targe_sum_pair(a,tar);
    return 0;
}