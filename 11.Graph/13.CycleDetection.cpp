#include<bits/stdc++.h>
using namespace std;
const int n=100;
vector<pair<int,int>> graph[n+1];
vector<bool> vis(n+1,false);

bool isCycleDfs(int u,int p){
    vis[u]=true;
    for(auto chld:graph[u]){
        if(vis[chld.first]==false){
            if(isCycleDfs(chld.first,u)==true){
                return true;
            }
        }else{
            if(chld.first != p){
                return true;
            }
        }
    }

    return false;
}

int main(){
        int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            if(isCycleDfs(i,-1)==true){
                cout<<"true"<<endl;
                return 0;
            }
        }
    }

    cout<<"false"<<endl;

    return 0;
}