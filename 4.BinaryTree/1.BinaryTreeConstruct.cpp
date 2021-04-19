#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
    }

    

};

int main(){
    int n;
    cin>>n;

    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(auto u:arr){
        cout<<u<<" ";
    }
    cout<<endl;

    return 0;
}