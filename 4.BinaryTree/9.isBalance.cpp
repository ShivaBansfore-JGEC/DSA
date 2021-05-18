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


bool is_balance=true;

int isBalance(Node *node){
    if(node==NULL){
        return -1;
    }

    int lTreeHeight=isBalance(node->left);
    int RtreeHeight=isBalance(node->right);

    if(abs(lTreeHeight-RtreeHeight)>1){
        is_balance=false;
    }

    return max(lTreeHeight,RtreeHeight)+1;
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


isBalance(root);
if(is_balance==true){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}




    return 0;
}