#include<bits/stdc++.h>
using namespace std;


void countSort(vector<string> &a,int div,int mod,int range){

    vector<int> fre(range,0);
    string ans[a.size()];

    //making frequency array
    for(int i=0;i<a.size();i++){
        fre[stoi(a[i])/div % mod]++;
    }

    //convering frequency array to prefix sum

    for(int i=1;i<range;i++){
        fre[i]+=fre[i-1];
    }

    for(int i=a.size()-1;i>=0;i--){
        int pos=fre[stoi(a[i])/div % mod]-1;
        ans[pos]=a[i];
        fre[stoi(a[i])/div % mod]--;
    }


    //filling the original array

    for(int i=0;i<a.size();i++){
        a[i]=ans[i];
    }
}

void sortDates(vector<string> &a){
    countSort(a,1000000,100,32); //sorting according to days
    countSort(a,10000,100,13); //sorting according to month
    countSort(a,1,10000,2501); //sorting according to year
}


int main(){
    int n;
    cin>>n;

    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sortDates(a);

    for(string u:a){
        cout<<u<<endl;
    }

    return 0;
}