#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans[n];
    ans[0]=1;
    stack<long long> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0){
            if(arr[st.top()]<=arr[i]){
                st.pop();
            }else{
                break;
            }
        }

        if(st.size()==0){
            ans[i]=i+1;
        }else{
            ans[i]=abs(i-st.top());
            
        }

        st.push(i);
    }

    for(long long u:ans){
        cout<<u<<endl;
    }

    return 0;
}