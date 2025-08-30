#include<bits/stdc++.h>
using namespace std;

void calculateDfs(int startNode,vector<int>adj[],int vis[],vector<int>dfsTraversal)
{

    vis[startNode]=1;
    dfsTraversal.push_back(startNode);

    for(auto it:adj[startNode])
    {
        if(!vis[it])
        {
            calculateDfs(it,adj,vis,dfsTraversal);
        }
    }

}

vector<int> returnDfsOfGraph(int v, vector<int>adj[])
{
    vector<int>dfsTraversal;
    int startNode =0;
    int vis[v] ={0};
    calculateDfs( startNode, adj,vis,dfsTraversal);
    return dfsTraversal;
}

int main()
{
    //graph
    // call  returnDfsOfGraph

    return 0;
}