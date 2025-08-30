#include <bits/stdc++.h>
using namespace std;

// Function to convert adjacency matrix to adjacency list
vector<vector<int>> convertToAdjList(vector<vector<int>> &adjMatrix) 
{
    // number of vertices
    int V = adjMatrix.size(); 
    vector<vector<int>> adjList(V);

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            if (adjMatrix[i][j] == 1 & i != j) 
            { 
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
}

// dfs Traversal
 void dfsTraversal(int startNode,int vis[],vector<vector<int>> &adjLs)
 {
    vis[startNode]=1;
    for(auto it: adjLs[startNode])
    {
        if(!vis[it])
        {
            dfsTraversal(it,vis,adjLs);
        }
    }

 }

 // find out number of provinces

 int numberOfProvinces(vector<vector<int>> &adjLs)
 {
    int v= adjLs.size();
    int vis[v] ={0};
    int cnt=0;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfsTraversal(i,vis,adjLs);
        }
    }
 }

int main() {
    
    vector<vector<int>> adjMatrix = 
    {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    vector<vector<int>> adjList = convertToAdjList(adjMatrix);

    // Print adjacency list
    for (int i = 0; i < adjList.size(); i++) 
    {
        cout << i << ": ";
        for (auto neighbor : adjList[i]) 
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}
