#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};


void LevelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    bool visited[1000];
    visited[root->data]=true;
    while(q.size()>0){
        Node *node=q.front();
        q.pop();
        cout<<node->data<<" ";
        for(Node *child:node->children){
            if(visited[child->data]==false){
                q.push(child);
                visited[node->data]=true;
            }
        }

    }
    cout<<"."<<endl;

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
    LevelOrder(root);
  
    return 0;
}