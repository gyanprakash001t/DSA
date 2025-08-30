#include<bits/stdc++.h>
using namespace std;

void dfsTraversal(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>> &image, int deltaRow[], int deltaCol[],int initialColor, int newColor)
{
    int n = image.size(); // row
    int m = image[0].size(); // col
    ans[sr][sc]=newColor;
    // traversing the neighbor
    for(int i=0;i<4;i++)
    {
        int neighborRow = sr + deltaRow[i];
        int neighborCol = sc + deltaCol[i];
        if(neighborRow >=0 && neighborRow<n && neighborCol>=0 && neighborCol<m && image[neighborRow][neighborCol]==initialColor && ans[neighborRow][neighborCol] != newColor)
        {
            dfsTraversal(neighborRow,neighborCol,ans,image,deltaRow,deltaCol,initialColor,newColor);
        }
    }



}

vector<vector<int>> floodFill(vector<vector<int>> image,int sr, int sc, int newColor )
{
  
    int initialColor = image[sr][sc];
    if (initialColor == newColor) return image;  // ⚡ important edge case
    int deltaRow[] = {-1,0,1,0};
    int deltaCol[]= {0,1,0,-1};
    vector<vector<int>> ans = image; // copy of image to modify 

    dfsTraversal(sr,sc,ans,image,deltaRow,deltaCol, initialColor ,newColor);
    return ans;

}