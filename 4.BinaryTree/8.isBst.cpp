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


class bstSolver{
    public:
    int maxx;
    int minn;
    bool isbst;
    bstSolver(int mn,int mx,bool isBst){
        maxx=mx;
        minn=mn;
        isbst=isBst;
    }
};

bstSolver isBst(Node *node){
    if(node==NULL){
        return bstSolver(INT_MAX,INT_MIN,true);
    }

    bstSolver lres=isBst(node->left);
    bstSolver Rres=isBst(node->right);

    int maxi=max(node->data,max(lres.maxx,Rres.maxx));
    int mini=min(node->data,min(lres.minn,Rres.minn));

    bool isbst=lres.isbst && Rres.isbst && node->data > lres.maxx && node->data <Rres.minn;

    return bstSolver(mini,maxi,isbst);
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


 bstSolver response= isBst(root);

 if(response.isbst==true){
     cout<<"true"<<endl;
 }else{
     cout<<"false"<<endl;
 }


    return 0;
}