#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10000000];
vector<bool> vis(10000000,false);


void bfs(int root){
    queue<int> q;
    q.push(root);
    vis[root]=true;
    while(q.size() > 0){
        int val=q.front();
        q.pop();
        cout<<val<<" ";
        for(int child:graph[val]){
            if(vis[child]==false){
                q.push(child);
                vis[child]=true;
            }
        }

    }
    cout<<endl;
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

    for(int i=1;i<=n;i++){
        if(vis[i]==false)
            bfs(i);
    }

    return 0;
}