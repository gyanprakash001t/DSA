#include<bits/stdc++.h>
using namespace std;

int main()
{
    // nodes and edges
    int n,m;
    cin>>n>>m;
    // graph using adjacency matrix
    int adj[n+1][m+1];
    for(int i=0; i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }

    // graph using adjacency list
    vector<int>arr[m+1];
    for(int i=0; i<m;i++)
    {
         int v,u;
         cin>>v>>u;
         arr[u].push_back(v);
         arr[v].push_back(u);  // in ase of directed graph  this line have to be removed cause v is neighbor of u but not vice-vercca andTC :O(E)
    } 
    return 0;

} 