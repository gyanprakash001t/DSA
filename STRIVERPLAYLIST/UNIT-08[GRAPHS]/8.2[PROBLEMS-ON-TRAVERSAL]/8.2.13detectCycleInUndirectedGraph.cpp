#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  bool dfs(int node, vector<int>&vis, vector<int> adjList[], vector<int>&pathVis)
  {
    vis[node]  =1;
    pathVis[node]=1;
    for(auto nbr :adjList[node])
    {
        if(!vis[nbr])
        {
            if(dfs(nbr,vis,adjList,pathVis)) return true;
        }
        else if(pathVis[nbr])
        {
            return true;
        }
    }
    pathVis[node] =0;
    return false;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
        //convert into adjList
        vector<int>adjList[V];
        for(auto it :edges)
        {
            adjList[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adjList,pathVis)) return true;
            }
        }
        return false;
    }
};