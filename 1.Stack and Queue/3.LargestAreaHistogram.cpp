#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int lb[n],rb[n];
    //find next smaller elment in left side 

    //find next smaller elment in right side

    stack<int> st1,st2;

    st1.push(0);
    st2.push(n-1);
    lb[0]=-1;
    for(int i=0;i<n;i++){
        while(st1.size()>0){
            if(arr[st1.top()]>=arr[i]){
                st1.pop();
            }else{
                break;
            }
        }

        if(st1.size()==0){
            lb[i]=-1;
        }else{
            lb[i]=st1.top();
        }

        st1.push(i);
    }
    rb[n-1]=n;
    for(int i=n-2;i>=0;i--){
        while(st2.size()>0){
            if(arr[st2.top()]>=arr[i]){
                st2.pop();
            }else{
                break;
            }
        }

        if(st2.size()==0){
            rb[i]=n;
        }else{
            rb[i]=st2.top();
        }

        st2.push(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        int w=rb[i]-lb[i]-1;
        ans=max(ans,w*arr[i]);

    }

    cout<<ans<<endl;

    return 0;
}