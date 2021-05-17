#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


int size(Node *node){
    if(node==NULL){
        return 0;
    }
    return size(node->left)+size(node->right)+1;
}

int height(Node *node){
    if(node==NULL){
        return -1;
    }

    return max(height(node->left),height(node->right))+1;
}

int sum(Node *node){
    if(node==NULL){
        return 0;
    }

    int lsum=sum(node->left);
    int rsum=sum(node->right);
    return lsum+rsum+node->data;
}

int maxi(Node *node){
    if(node==NULL){
        return INT_MIN;
    }

    int lmax=maxi(node->left);
    int rmax=maxi(node->right);

    return max(max(lmax,rmax),node->data);
}



int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="n"){
            arr[i]=INT_MAX;
        }else{
            arr[i]=stoi(s);
        }
    }
    stack<pair<Node*,int>> st;
    Node *root=new Node(arr[0]);
    st.push(make_pair(root,1));
    int idx=0;
    while(st.size()>0){
        pair<Node *,int> tp=st.top();

        if(tp.second==1){
            idx++;
            st.top().second++;
            if(arr[idx]!=INT_MAX){
                Node *node=new Node(arr[idx]);
                st.top().first->left=node;
                st.push({node,1});
            }else{
                st.top().first->left=NULL;
            }


        }else if(tp.second==2){
            idx++;
            st.top().second++;
            if(arr[idx]!=INT_MAX){
                Node *node=new Node(arr[idx]);
                st.top().first->right=node;
                st.push({node,1});
            }else{
                st.top().first->right=NULL;
            }

        }else{
            st.pop();
        }

    }

    cout<<size(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<maxi(root)<<endl;
    cout<<height(root)<<endl;



    return 0;
}