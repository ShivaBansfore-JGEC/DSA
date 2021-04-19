#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


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


void removeLeaves(Node *root){
    for(int i=root->children.size()-1;i>=0;i--){
        Node *node=root->children[i];
        if(node->children.size()==0){
            node->children.erase(node->children.begin()+i);
        }
    }

    for(Node *child:root->children){
        removeLeaves(child);
    }
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


 //removeLeaves(root);
 display(root);
    return 0;
}