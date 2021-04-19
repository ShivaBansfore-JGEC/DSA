#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};



vector<int> NodeToRootPath(Node *root,int val){
    if(root->data==val)
    {
        vector<int> ans;
        ans.push_back(val);
        return ans;
    }
    vector<int> res;
    for(Node *child:root->children){
        res=NodeToRootPath(child,val);
        if(res.size()>0){
            res.push_back(root->data);
            return res;
        }
    }

    return res;
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
    
    vector<int> ans=NodeToRootPath(root,val);
    
    for(int u:ans){
        cout<<u<<" ";
    }

    cout<<endl;
  
    return 0;
}