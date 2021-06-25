#include<bits/stdc++.h>
using namespace std;

int graph[1000][1000];
vector<vector<bool>> vis(1000,vector<bool>(1000,false));


void dfs(int cr,int cc,int n,int m){
    if(cr <0 || cc < 0 || cr >=n || cc>=m || vis[cr][cc]==true || graph[cr][cc]==1){
        return;
    }

    vis[cr][cc]=true;
    dfs(cr,cc+1,n,m);
    dfs(cr,cc-1,n,m);
    dfs(cr-1,cc,n,m);
    dfs(cr+1,cc,n,m);

}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }

    int comp=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0 && vis[i][j]==false){
                comp++;
                dfs(i,j,n,m);
            }
        }
    }
    cout<<comp<<endl;

    return 0;
}