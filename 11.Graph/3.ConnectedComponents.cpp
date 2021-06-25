#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000000];
vector<bool> vis(10000000,false);

void dfs(int u){
    vis[u]=true;
    for(int c:graph[u]){
        if(vis[c]==false){
            dfs(c);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int comp=0;

    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            comp++;
            dfs(i);
        }
    }

    cout<<comp<<endl;

}