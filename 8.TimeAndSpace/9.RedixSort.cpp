#include<bits/stdc++.h>
using namespace std;



void printArr(vector<int> &a){
    for(int u:a){
        cout<<u<<" ";
    }
    cout<<endl;
}


void countSort(vector<int> &a,int exp){
    vector<int> fr(10,0);

    //make frequency array
    for(int i=0;i<a.size();i++){
        fr[(a[i] /exp)%10]++;
    }


    //convert it into prefix sum array*-
    for(int i=1;i<fr.size();i++){
        fr[i]+=fr[i-1];
    }



    int ans[a.size()];

    for(int i=a.size()-1;i>=0;i--){

        int pos=fr[a[i] /exp %10]-1;
        ans[pos]=a[i];
        fr[a[i] /exp %10]--;
    }

    for(int i=0;i<a.size();i++){
        a[i]=ans[i];
    }

    cout<<("After sorting on " + to_string(exp) + " place -> ");
    printArr(a);

}

void redixSort(vector<int> &a,int mx){
    int exp=1;

    while(exp<=mx){
        countSort(a,exp);
        exp=exp * 10;
    }
}


int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }

    redixSort(a,mx);
    printArr(a);


    return 0;
}