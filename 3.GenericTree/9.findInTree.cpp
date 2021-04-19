#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};



bool findInTree(Node *root,int val){
    
    if(root->data==val){
        return true;
    }

    bool ans=false;
    for(Node *child:root->children){
        ans=findInTree(child,val);
        if(ans==true){
            return true;
        }
    }

    return ans;
    
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
    bool ans=findInTree(root,val);
    if(ans){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
  

  vector<int> a={1,2,3,4,5};
  

    return 0;
}