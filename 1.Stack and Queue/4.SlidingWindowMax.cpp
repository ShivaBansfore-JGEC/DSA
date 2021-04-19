#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    long long arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long k;
    cin>>k;

    int ngr[n];
    stack<int> st;
    ngr[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0){
            if(arr[i]>=arr[st.top()]){
                st.pop();
            }else{
                break;
            }
        }

        if(st.size()==0){
            ngr[i]=n;
        }else{
            ngr[i]=st.top();
        }
        st.push(i);

    }
    int j=0;
    for(int i=0;i<=n-k;i++){
        if(j<i) j=i;
        
        while(ngr[j]<i+k){
            j=ngr[j];
        }
        cout<<arr[j]<<endl;
    }

    return 0;
}