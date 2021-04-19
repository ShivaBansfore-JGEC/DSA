#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans[n];
    ans[n-1]=-1;

    stack<int> st;
    st.push(arr[n-1]);
    
    for(int i=n-2;i>=0;i--){
        int cur=arr[i];
        while(st.size()>0){
            if(st.top()<=cur){
                st.pop();
            }else{
                break;
            }
        }
        if(st.size()==0){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
        st.push(cur);
    }

    for(int u:ans){
        cout<<u<<endl;
    }


}