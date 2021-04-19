#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};

int height(Node *root){

    int ht=0;
    for(Node *child:root->children){
        ht=max(ht,1+height(child));
    }
    return ht;
}

int main(){
    int n;
    cin>>n;
    int input_arr[n];
    for(int i=0;i<n;i++) cin>>input_arr[i];

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

    cout<<height(root)<<endl;

    return 0;
}