#include<bits/stdc++.h>
using namespace std;


struct node{
    int u,v,w;
    node(int first,int second,int wt){
        u=first;
        v=second;
        w=wt;
    }
};

bool compare(const node n1,const node n2){
    return n1.w < n2.w;
}



int findPar(int node,vector<int> &parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node]=findPar(parent[node],parent);
}

void Union(int u,int v,vector<int> &Rank,vector<int> &parent){
    u=findPar(u,parent);
    v=findPar(v,parent);

    if(Rank[u] > Rank[v]){
        parent[v]=u;
        Rank[u]++;
    }else if(Rank[v] > Rank[u]){
        parent[u]=v;
        Rank[v]++;
    }else{
        parent[v]=u;
        Rank[u]++;
    }

}


int main(){

    int n,m;
    cin>>n>>m;

    vector<node> graph;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(node(u,v,w));
        graph.push_back(node(u,v,w));
    }

    sort(graph.begin(),graph.end(),compare);
    vector<int> parent(n+1),Rank(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    int cost=0;
    vector<pair<int,int>> mst;
    for(int i=0;i<graph.size();i++){
        if(findPar(graph[i].u,parent)!=findPar(graph[i].v,parent)){
            Union(graph[i].u,graph[i].v,Rank,parent);
            cost+=graph[i].w;
            mst.push_back({graph[i].u,graph[i].v});
        }

    }
    cout<<cost<<endl;

    for(auto mstt:mst){
        cout<<mstt.first<<" "<<mstt.second<<endl;
    }




    return 0;
}