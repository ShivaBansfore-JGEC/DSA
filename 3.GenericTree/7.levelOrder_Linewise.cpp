#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};



void level_order_linewise(Node * root){
    queue<Node*> mainQ,helperQ;
    mainQ.push(root);

    while(mainQ.size()>0){
        Node *node=mainQ.front();
        mainQ.pop();
        cout<<node->data<<" ";

        for(Node *child:node->children){
            helperQ.push(child);
        }

        if(mainQ.size()==0){
            cout<<endl;
            queue<Node*> temp=mainQ;
            mainQ=helperQ;
            helperQ=temp;
        }
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

    level_order_linewise(root);

    return 0;
}