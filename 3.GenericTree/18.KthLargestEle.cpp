#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


int c=INT_MAX;
int f=INT_MIN;


void ceil_floor(Node *root,int val){
    if(root->data<val){
        f=max(f,root->data);
    }else if(root->data>val){
        c=min(c,root->data);
    }

    for(Node *child:root->children){
        ceil_floor(child,val);
    }
}

void findKthLargest(Node *root,int k){

    int ans=INT_MAX;
    for(int i=0;i<k;i++){
        ceil_floor(root,ans);
        ans=f;
        f=INT_MIN;
    }

    cout<<ans<<endl;
}

int main(){
    int n;
    cin>>n;
    int input_arr[n];
    for(int i=0;i<n;i++) cin>>input_arr[i];
    int k;
    cin>>k;
    Node *root=NULL;
    stack<Node *> st;

    for(int i=0;i<n;i++){
        if(input_arr[i]==-1){
            if(st.size()>0){
                st.pop();
            }
        }else{
            Node *new_node=new Node();
            new_node->data=input_arr[i];
            if(st.size()>0){
                st.top()->children.push_back(new_node);
            }else{
                root=new_node;
            }
            st.push(new_node);
        }
    }
    findKthLargest(root,k);
    return 0;
}