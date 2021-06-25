#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1000];
vector<int> color(1000,-1);

bool bfs(int root,int c){
    queue<int> q;
    q.push(root);
    color[root]=c;

    while(q.size() > 0){
        int parent=q.front();
        q.pop();

        for(auto child:graph[parent]){
            if(color[child.first]==-1){
                color[child.first]=(color[parent]^1);
                q.push(child.first);
            }else{
                if(color[parent]==color[child.first]){
                    return false;
                }
            }
        }
    }

    return true;
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

    bool ans=true;
    for(int i=0;i<=n;i++){
        if(color[i]==-1){
            if(bfs(i,0)==false){
                ans=false;
                break;
            }
        }
    }

    ans ? cout<<"true" : cout<<"false";
    return 0;
}