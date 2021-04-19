#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


Node *predecessor=NULL,*successor=NULL;
int state=0;

void findPredeccessorSuccessor(Node *node,int val){

    if(state==0){
        if(node->data==val){
            state++;
        }else{
            predecessor=node;
        }

    }else if(state==1){
        successor=node;
        state++;
    }

    for(Node *child:node->children){
        findPredeccessorSuccessor(child,val);
    }

}

int main(){
    int n;
    cin>>n;
    int input_arr[n];
    for(int i=0;i<n;i++) cin>>input_arr[i];
    int val;
    cin>>val;

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

    findPredeccessorSuccessor(root,val);
    if(predecessor==NULL){
        cout<<"Predecessor = Not found"<<endl;
    }else
        cout<<"Predecessor = "<<predecessor->data<<endl;

    if(successor==NULL){
        cout<<"Successor = Not found"<<endl;
    }else
        cout<<"Successor = "<<successor->data<<" "<<endl;



    return 0;
}