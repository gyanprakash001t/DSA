#include<bits/stdc++.h>
using namespace std;

bool biBipartiteGraph(vector<int>adjList[], int v)
{   
    int start =1;
    int color =0;
    int vis[v] ={v,-1};
    vis[start]= color;
    queue<pair<int, int>>q;
    q.push({start,color}); 

     while(!q.empty())
     {
        int node = q.front().first;
        int parentColor = q.front().second;
        q.pop();
        for(auto it : adjList[node])
        {
            if(vis[it] == -1)
            {
                
                
                vis[it] = !parentColor;
                q.push({it,  vis[it]});
            }

            // logic to find out if neighbors have same color
            if(parentColor == color)
            {
                return false;
            }
        }
     }
     return true;

}