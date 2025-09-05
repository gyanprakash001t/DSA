#include<bits/stdc++.h>
using namespace std;
void dfs (int row, int col,vector<vector<int>>& vis, vector<vector<int>>& matrix, vector<pair<int,int>>& sequence,int rowStart, int colStart)
{
   sequence.push_back({row-rowStart,col-colStart});
   int delRow[] ={-1,0,1,0};
   int delCol[]={0,1,0,-1};
   vis[row][col] =1;

   for(int i=0; i<4; i++)
   {
    int nRow = row + delRow[i];
    int nCol = col + delCol[i];
    if( !vis[nRow][nCol] &&  matrix[row][col]==1 && nRow >= 0 && nRow < matrix.size() && nCol >= 0 && nCol < matrix[0].size())
    {
        // sequence.push_back({nRow-rowStart,nCol-colStart});
        dfs(nRow,nCol,vis,matrix,sequence,nRow,nCol);
    }
   }

}

int numberOfDistinctIslands(vector<vector<int>>&matrix)
{
    int m = matrix.size();
    int n= matrix[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    set<vector<pair<int,int>>>st;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!vis[i][j] && matrix[i][j]==1)
            {
                vector<pair<int,int>>sequence;  
                // each time you'll start  a new sequece(island) so we are considering first one as origin point that's why we ahve passed them rowStart, colStart 
                dfs(i,j,vis,matrix,sequence,i,j);
                st.insert(sequence);
            }
            
        }
    }
    return st.size();

}