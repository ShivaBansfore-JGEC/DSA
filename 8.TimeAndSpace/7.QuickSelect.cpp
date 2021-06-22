#include<bits/stdc++.h>
using namespace std;

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j) {
    cout<<("Swapping " + to_string(arr[i]) + " and " + to_string(arr[j]))<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(vector<int> &arr, int pivot, int lo, int hi) {
    cout<<("pivot -> " + to_string(pivot))<<endl;
    int i = lo, j = lo;
    while (i <= hi) {
      if (arr[i] <= pivot) {
        swap(arr, i, j);
        i++;
        j++;
      } else {
        i++;
      }
    }
    cout<<("pivot index -> " + to_string((j - 1)))<<endl;
    return (j - 1);
  }


int QuickSelect(vector<int> &arr,int lo,int hi,int k){
    int pivot=arr[hi];
    int pi=partition(arr,pivot,lo,hi);
    cout<<"pi---->"<<pi<<endl;

    if(k > pi){
        return QuickSelect(arr,pi+1,hi,k);
    }else if(k < pi){
        return QuickSelect(arr,lo,pi-1,k);
    }else{
        return pivot;
    }
   
}


int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    int ans=QuickSelect(a,0,n-1,k-1);
    cout<<ans<<endl;
    return 0;
}