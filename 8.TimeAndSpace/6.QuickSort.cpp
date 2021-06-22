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


void QuickSort(vector<int> &arr,int lo,int hi){
    if(lo > hi){
        return;
    }
    int pivot=arr[hi];
    int pi=partition(arr,pivot,lo,hi);
    QuickSort(arr,lo,pi-1);
    QuickSort(arr,pi+1,hi);
}


int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    QuickSort(a,0,n-1);

    for(int u:a){
        cout<<u<<" ";
    }
    cout<<endl;

    
    return 0;
}