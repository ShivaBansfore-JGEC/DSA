#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


bool find(Node *node,int data){
    if(node==NULL){
        return false;
    }

    if(node->data==data){
        return true;
    }

    bool leftTreeResponse=find(node->left,data);
    if(leftTreeResponse==true){
        return true;
    }

    bool rightTreeResponse=find(node->right,data);

    if(rightTreeResponse==true){
        return true;
    }

    return false;
    
}


vector<Node*> rootToNodePath(Node *node,int val){
    if(node==NULL){
        vector<Node*> base;
        return base;
    }

    if(node->data==val){
        vector<Node*> base;
        base.push_back(node);
        return base;
    }

    vector<Node*> leftAndRightTreeResponse;

    leftAndRightTreeResponse=rootToNodePath(node->left,val);
    if(leftAndRightTreeResponse.size() > 0){
        leftAndRightTreeResponse.push_back(node);
        return leftAndRightTreeResponse;
    }

    leftAndRightTreeResponse=rootToNodePath(node->right,val);
    if(leftAndRightTreeResponse.size() > 0){
        leftAndRightTreeResponse.push_back(node);
        return leftAndRightTreeResponse;
    }

    return leftAndRightTreeResponse;


}

void PrintKlevelDown(Node *node,int k){
    if(node==NULL){
        return;
    }

    if(k==0){
        cout<<node->data<<endl;
        return;
    }


    PrintKlevelDown(node->left,k-1);
    PrintKlevelDown(node->right,k-1);

}



void KlevelDistance(Node *node,int data,int k)
{
    vector<Node*> res=rootToNodePath(node,data);
    Node *pre=NULL;

    PrintKlevelDown(res[0],k);
    for(int i=1;i<res.size();i++){
        int rem=k-i;
        Node *prev=res[i-1];
        Node *curr=res[i];

        if(rem==0){
            cout<<res[i]->data<<endl;
            return;
        }
        if(prev==curr->left){
            PrintKlevelDown(res[i]->right,rem-1);
        }else{
            PrintKlevelDown(res[i]->left,rem-1);
        }
        pre=res[i];
    }

}



int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="n"){
            arr[i]=INT_MAX;
        }else{
            arr[i]=stoi(s);
        }
    }

    int k,data;
    cin>>data>>k;
    stack<pair<Node*,int>> st;
    Node *root=new Node(arr[0]);
    st.push(make_pair(root,1));
    int idx=0;
    while(st.size()>0){
        pair<Node *,int> tp=st.top();

        if(tp.second==1){
            idx++;
            st.top().second++;
            if(arr[idx]!=INT_MAX){
                Node *node=new Node(arr[idx]);
                st.top().first->left=node;
                st.push({node,1});
            }else{
                st.top().first->left=NULL;
            }


        }else if(tp.second==2){
            idx++;
            st.top().second++;
            if(arr[idx]!=INT_MAX){
                Node *node=new Node(arr[idx]);
                st.top().first->right=node;
                st.push({node,1});
            }else{
                st.top().first->right=NULL;
            }

        }else{
            st.pop();
        }

    }


KlevelDistance(root,data,k);


    return 0;
}