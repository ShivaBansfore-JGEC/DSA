#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};



void level_order_linewiseZigzag(Node * root){
    stack<Node*> mainQ,helperQ;
    mainQ.push(root);
    int level=0;
    while(mainQ.size()>0){
        Node *node=mainQ.top();
        mainQ.pop();
        cout<<node->data<<" ";

        if(level%2==0){
            for(Node *child:node->children){
                helperQ.push(child);
            }
        }else{
            for(int i=node->children.size()-1;i>=0;i--){
                helperQ.push(node->children[i]);
            }
        }

        if(mainQ.size()==0){
            cout<<endl;
            stack<Node*> temp=mainQ;
            mainQ=helperQ;
            helperQ=temp;
            level++;
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

    level_order_linewiseZigzag(root);

    return 0;
}