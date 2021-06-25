#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(100,false);
vector<int> graph[100];
void dfs(int u,int p){
    cout<<u<<endl;
    vis[u]=true;

    for(int child:graph[u]){
        if(vis[child]==false){
            dfs(child,u);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    graph->resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

dfs(1,0);

/*

    weighted graph representation:
        vector<pair<int,int>> graph[n+1];
        for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({v,w});
        }

*/

    return 0;
}