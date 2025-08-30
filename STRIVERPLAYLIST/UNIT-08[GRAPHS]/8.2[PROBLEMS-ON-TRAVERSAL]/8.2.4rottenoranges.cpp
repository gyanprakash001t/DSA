   #include<bits/stdc++.h>
   using namespace std;
   
   int orangesRotting(vector<vector<int>>& grid) 
   {
        int n = grid.size();
        int m = grid[0].size();
        int deltaRow[]={-1,0,1,0};
        int deltaCol[] ={0,1,0,-1};
        queue<pair<pair<int, int>,int>> q;
        int minTime=0;
        vector<vector<int>>vis(n,vector<int>(m, 0));
        for(int i=0 ;i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;

                }
            }
        }

        
        while( !q.empty())
        {
            auto rotten = q.front();
            q.pop();
            int row = rotten.first.first;
            int col = rotten.first.second;
            int time = rotten.second;
            minTime =time;
            

            for(int i=0;i<4;i++)
            {
                int  neighborRow = row + deltaRow[i];
                int  neighborCol = col + deltaCol[i];
                if(neighborRow >=0 &&neighborRow <n && neighborCol>=0 && neighborCol<m && !vis[neighborRow][neighborCol] && grid[neighborRow][neighborCol] ==1)
                {
                    grid[neighborRow][neighborCol] = 2;

                    vis[neighborRow][neighborCol] =2;
                    q.push({{neighborRow,neighborCol},time+1});
                }
                
            }

            
            
        }
    }