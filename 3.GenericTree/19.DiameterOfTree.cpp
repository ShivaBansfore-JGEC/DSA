#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};



int dia;
int DiameterOfTree(Node *root){
    int lh=-1,slh=-1;
    for(Node *child:root->children){
        int cht=DiameterOfTree(child);
        if(cht>lh){
            slh=lh;
            lh=cht;
        }else if(cht>slh){
            slh=cht;
        }
    }

    int diameter=lh+slh+2;
    dia=max(dia,diameter);
    
    return lh+1;

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

    dia=0;
    DiameterOfTree(root);
    cout<<dia<<endl;
    return 0;
}