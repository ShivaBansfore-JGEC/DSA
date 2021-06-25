#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1000];
vector<int> color(1000,-1);


bool dfs(int u,int c){
    color[u]=c;
    for(auto pair:graph[u]){
        if(color[pair.first]==-1){
            if(dfs(pair.first,c^1)==false){
                return false;
            }
        }else{
            if(color[u]==color[pair.first]){
                return false;
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
            if(dfs(i,0)==false){
                ans=false;
                break;
            }
        }
    }

    ans ? cout<<"true" : cout<<"false";


    return 0;
}