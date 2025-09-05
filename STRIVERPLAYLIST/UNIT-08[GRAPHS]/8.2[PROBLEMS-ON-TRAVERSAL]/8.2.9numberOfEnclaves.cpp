#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int cnt =0;
        
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
               
                    if( grid[i][j]==1 && (i==0 || i==m-1 || j==0 || j==n-1))
                    {
                        vis[i][j] =1;
                        q.push({i,j});
                    
                    }
              
            }
        }

        while(!q.empty())
        {
            int row  = q.front().first;
            int col =  q. front().second;
            q.pop();
            for(int i=0; i<4;i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >=0 && nCol>=0 && nRow<m && nCol<n &&  grid[nRow][nCol] && !vis[nRow][nCol])
                {
                    vis[nRow][nCol] =1;
                    q.push({nRow,nCol});
                }
            }
        }

        // we'// travel through visited array  and find out 1's  which arenot visited  that means starting from those lands(1's) we can't reach to the boundary

        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
               if(grid[i][j] ==1  &&  !vis[i][j])
               {
                    cnt++;
               }
            }
        }
        return cnt;

        
    }
};