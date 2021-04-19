#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


int c=INT_MAX;
int f=INT_MIN;

void display(Node *node){
    string str=to_string(node->data)+"->";
    for(Node *child:node->children){
        str+=to_string(child->data)+",";
    }
    str+=".";
    cout<<str<<endl;
    for(Node *child:node->children){
        display(child);
    }
}



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
ceil_floor(root,k);
    cout<<c<<endl;
    cout<<f<<endl;

 //display(root);
    return 0;
}