#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> graph[n+1];

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
/*

find the minimum adjacent with the minimum weight val

add it to the current node

*/


priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;

pq.push({0,1});

vector<int> mst(n+1,0),parent(n+1),key(n+1,INT_MAX);


for(int i=1;i<=n;i++){

    int u=pq.top().second;
    pq.pop();
    mst[u]=1;

    for(auto p:graph[u]){
        int v=p.first;
        int wt=p.second;

        if(mst[v]==0 && wt < key[v]){
            parent[v]=u;
            key[v]=wt;
            pq.push({key[v],v});
        }
    }

}


for(int i=2;i<=n;i++){
    cout<<parent[i]<<"->"<<i<<endl;
}




    return 0;
}