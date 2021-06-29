#include<bits/stdc++.h>
using namespace std;

struct Node{
    int u,v,w;
    Node(int first,int second,int weight){
        u=first;
        v=second;
        w=weight;
    }
};

bool comp(const Node d1,const Node d2){
    return d1.w < d2.w;
}


int findPar(int u,vector<int> &parent){

    if(parent[u]==u){
        return u;
    }

    return parent[u]=findPar(parent[u],parent);

}

void Union(int u,int v,vector<int> &par,vector<int> &Rank){

    u=findPar(u,par);
    v=findPar(v,par);

    if(Rank[u] > Rank[v]){
        par[v]=u;
        Rank[u]++;
    }else if(Rank[v] > Rank[u]){
        par[u]=v;
        Rank[v]++;
    }else{
        par[v]=u;
        Rank[u]++;
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<Node> graph;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(Node(u,v,w));
    }

    sort(graph.begin(),graph.end(),comp);

    vector<int> parent(n+1),Rank(n+1,0);

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    vector<pair<int,int>> mst;
    int cost=0;
    for(auto G:graph){
        if(findPar(G.u,parent)!=findPar(G.v,parent)){
            cost+=(G.w);
            mst.push_back({G.u,G.v});
            Union(G.u,G.v,parent,Rank);
        }
    }



    cout<<cost<<endl;
    for(auto e:mst){
        cout<<e.first<<" "<<e.second<<endl;
    }


    cout<<(3^1^3)<<endl;



    
    return 0;
}