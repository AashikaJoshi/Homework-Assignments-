#include <iostream>
using namespace std;

int adj[100][100],n;
bool vis[100];

void dfs(int u){
    vis[u]=true;
    cout<<u<<" ";
    for(int i=0;i<n;i++){
        if(adj[u][i]==1 && !vis[i]) dfs(i);
    }
}

int main(){
    int e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
    cin>>start;
    dfs(start);
}