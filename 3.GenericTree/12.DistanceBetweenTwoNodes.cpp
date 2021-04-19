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


int lowestCommonAncestor(Node *root,int val1,int val2){

    vector<int> val1Path=NodeToRootPath(root,val1);
    vector<int> val2Path=NodeToRootPath(root,val2);
    int lca=0,i=val1Path.size()-1,j=val2Path.size()-1;

    while(i>=0 && j >=0){
        if(val1Path[i]==val2Path[j]){
            lca=val1Path[i];
        }
        i--;
        j--;
    }

    return lca;
}


void distanceBetweenTwoNode(Node *root,int val1,int val2){
    vector<int> val1Path=NodeToRootPath(root,val1);
    vector<int> val2Path=NodeToRootPath(root,val2);

    int lca=lowestCommonAncestor(root,val1,val2);
    int ans=0;
    for(int i=0;i<val1Path.size();i++){
        if(val1Path[i]==lca){
            break;
        }else{
            ans++;
        }
    }

    for(int i=0;i<val2Path.size();i++){
        if(val2Path[i]==lca){
            break;
        }else{
            ans++;
        }
    }

    cout<<ans<<endl;
}


int main(){
    int n;
    cin>>n;
    int input_arr[n];
    for(int i=0;i<n;i++) cin>>input_arr[i];
    int val1,val2;
    cin>>val1>>val2;

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
   distanceBetweenTwoNode(root,val1,val2);
  
    return 0;
}