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


void PrintSingleChild(Node *node){
    if(node==NULL){
        return;
    }

    if(node->left!=NULL && node->right==NULL){
        cout<<node->left->data<<endl;
        PrintSingleChild(node->left);
    }else if(node->right!=NULL && node->left==NULL){
        cout<<node->right->data<<endl;
        PrintSingleChild(node->right);
    }else{
        PrintSingleChild(node->left);
        PrintSingleChild(node->right);
        
    }

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


PrintSingleChild(root);


    return 0;
}