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



// MINIMUM SPANNING TREE IMPLEMENTATION TIME COMPLEXITY-> O((v+e)log(n))


    vector<int> key(n+1,INT_MAX),mst(n+1,0),parent(n+1,-1);
    key[1]=0;


    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({1,1});

    for(int i=1;i<=n;i++){

       int u=pq.top().second;
        pq.pop();

        mst[u]=1;

        for(auto vtx:graph[u]){
            int v=vtx.first;
            int weight=vtx.second;
            if(mst[v]==0 && weight < key[v]){
                parent[v]=u;
                key[v]=weight;
                pq.push({key[v],v});
            }

        }
    }

    for(int i=2;i<=n;i++){
        cout<<parent[i]<<"-->"<<i<<endl;
    }

    return 0;
}