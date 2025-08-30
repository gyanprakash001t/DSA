#include<bits/stdc++.h>
using namespace std;


void bfsTraversal(int row, int col, vector<vector<char>> &grid,vector<vector<int>> & vis)
{
    int n = grid.size(); // rows
    int m = grid[0].size(); // col
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    
    while(!q.empty())
    {
        int row =q.front().first;
        int col = q.front().second;
        q.pop();
        // travrese the neighbors(in 8-dirn)
        for(int deltaRow =-1 ; deltaRow<=1; deltaRow++)
        {
            for(int deltaCol = -1; deltaCol <=1; deltaCol++)
            {
                int neighborRow = row + deltaRow;
                int neighborCol = col+ deltaCol; 
                if(neighborRow >=0 && neighborRow<n && neighborCol>=0 && neighborCol < m && !vis[neighborRow][neighborCol] && grid[neighborRow][neighborCol] == '1') 
                {
                    

                    vis[neighborRow][neighborCol]=1;
                    q.push({neighborRow,neighborCol});
                }
            }
        }
    }
}

int numberOfIslands(vector<vector<char>>&grid)
{
    int n = grid.size(); // rows
    int m = grid[0].size(); // col
    vector<vector<int>> vis(n, vector<int>(m, 0));  // nXm matrix;

    int cnt =0;

    // now  i have to travel every cell

    for(int row=0; row<n;row++)
    {
        for(int col =0;col<m;col++)
        {
            if( !vis[row][col] && grid[row][col]=='1')
            {
                cnt++;
                bfsTraversal(row,col,grid,vis);
            }
        }
    }
    return cnt;

}