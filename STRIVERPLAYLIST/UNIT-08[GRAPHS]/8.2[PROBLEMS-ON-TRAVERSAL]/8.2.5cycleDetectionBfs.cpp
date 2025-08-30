#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  bool detect(int src, vector<int> adjLs[], int vis[]) 
  {
      vis[src] = 1; 
      queue<pair<int,int>> q; 
      q.push({src, -1}); 

      while(!q.empty()) 
      {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          
          for(auto adjacentNode: adjLs[node]) 
          {
              
           if(!vis[adjacentNode])
           {
            vis[adjacentNode]=1;
            q.push({adjacentNode,node});
           }
           else if(parent != adjacentNode ) 
        // see.. previous node is the parent and now  you are on the current node  
        // so if you travers the neighbors  they must be unvisited or equal to the parent that means 
        // you have  came to this node via parent node and this can't be a cycle but  if you are on a neighbor and it's visited but 
        // also not euals to the parent means someone else visited  or you can say some other node also  crossing the paths means there's a cycle

           {

            return true; // then yes there must be a cycle
           }
          }
      }
      
      return false; 
  }
  public:
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) 
        {
            if(!vis[i]) 
            {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}