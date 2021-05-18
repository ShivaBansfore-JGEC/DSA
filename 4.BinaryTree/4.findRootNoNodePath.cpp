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


bool find(Node *node,int data){
    if(node==NULL){
        return false;
    }

    if(node->data==data){
        return true;
    }

    bool leftTreeResponse=find(node->left,data);
    if(leftTreeResponse==true){
        return true;
    }

    bool rightTreeResponse=find(node->right,data);

    if(rightTreeResponse==true){
        return true;
    }

    return false;
    
}


vector<int> rootToNodePath(Node *node,int val){
    if(node==NULL){
        vector<int> base;
        return base;
    }

    if(node->data==val){
        vector<int> base;
        base.push_back(node->data);
        return base;
    }

    vector<int> leftAndRightTreeResponse;

    leftAndRightTreeResponse=rootToNodePath(node->left,val);
    if(leftAndRightTreeResponse.size() > 0){
        leftAndRightTreeResponse.push_back(node->data);
        return leftAndRightTreeResponse;
    }

    leftAndRightTreeResponse=rootToNodePath(node->right,val);
    if(leftAndRightTreeResponse.size() > 0){
        leftAndRightTreeResponse.push_back(node->data);
        return leftAndRightTreeResponse;
    }

    return leftAndRightTreeResponse;


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

    int val;
    cin>>val;

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


cout<<find(root,val)<<endl;
vector<int> ans=rootToNodePath(root,val);

for(int u:ans){
    cout<<u<<" ";
}

cout<<endl;


    return 0;
}