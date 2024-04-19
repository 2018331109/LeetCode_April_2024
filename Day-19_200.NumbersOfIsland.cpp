/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution
{
public:
    int n=0, m=0, ans=0;
    void call(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& check)
    {
        if(i<0 or j<0 or i>=n or j>=m or check[i][j] or grid[i][j]=='0')
        {
            return;
        }
        check[i][j]=1;
        call(i+1, j, grid, check);
        call(i-1, j, grid, check);
        call(i, j+1, grid, check);
        call(i, j-1, grid, check);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        n=grid.size(), m=grid[0].size();
        vector<vector<int>>check(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1' and check[i][j]==0)
                {
                    ans++;
                    call(i, j, grid, check);
                }
            }
        }
        return ans;

    }
};

