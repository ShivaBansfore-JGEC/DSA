#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> wt_graph[100];

vector<bool> vis(100);
void dfs(int u,int p){
    
    

    vis[u]=true;

    for(pair<int,int> p:wt_graph[u]){
        if(vis[p.first]==false){
            dfs(p.first,u);
        }else{
            cout<<u<<" "<<p.second<<endl;
        }
    }

}


int main(){

    int n ,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        wt_graph[u].push_back({v,w});
        wt_graph[v].push_back({u,w});
    }

    dfs(1,0);
    return 0;
}