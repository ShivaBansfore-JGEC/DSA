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

    int src;
    cin>>src;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> dist(n+1,INT_MAX);

    dist[src]=0;

    pq.push({0,src});
    while(pq.size() > 0){

        pair<int,int> parent=pq.top();
        pq.pop();

        for(auto child:graph[parent.second]){
            //cout<<"{"<<parent.first<<"--->"<<parent.second<<" --> "<<child.first<< " "<<child.second<<"},";
            if(dist[child.first] > (parent.first+child.second)){
                dist[child.first]=(parent.first+child.second);
                cout<<child.first<<"->"<<dist[child.first]<<endl;
                pq.push({dist[child.first],child.first});
            }
        }
        cout<<endl;
    }

    for(int i=0;i<=n;i++){
        cout<<dist[i]<<" ";
    }

    cout<<endl;

    return 0;
}