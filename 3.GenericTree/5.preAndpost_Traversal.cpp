#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


void traversal(Node *node){
    cout<<"Node Pre "<<node->data<<endl;
    for(Node *child:node->children){
        cout<<"Edge Pre "<<node->data<<"--"<<child->data<<endl;
        traversal(child);
        cout<<"Edge Post "<<node->data<<"--"<<child->data<<endl;
    }
    cout<<"Node Post "<<node->data<<endl;
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

    traversal(root);
    return 0;
}