#include<bits/stdc++.h>
using namespace std;


void swap(vector<int> &arr, int i, int j) {
    cout<<("Swapping index " + to_string(i) + " and index " + to_string(j))<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &a,int n){

    int i=0,j=0,k=n-1;
    while(i <= k){
        if(a[i]==0){
            swap(a,i,j);
            i++;
            j++;
        }else if(a[i]==1){
            i++;
        }else{
            swap(a,i,k);
            k--;
        }
    }

    for(int u:a){
        cout<<u<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort012(a,n);

    // for(int u:a){
    //     cout<<u<<endl;
    // }

    return 0;
}