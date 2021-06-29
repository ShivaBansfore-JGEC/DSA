#include<bits/stdc++.h>
using namespace std;

vector<int> parent(1000),Rank(1000,0);

void makeset(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
}

int findParent(int u){
    if(parent[u]==u){
        return u;
    }

    return parent[u]=findParent(parent[u]);
}

void unionByrank(int u,int v){
    u=findParent(u);
    v=findParent(v);

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

    int n;
    cin>>n;
    makeset(n);

    return 0;
}