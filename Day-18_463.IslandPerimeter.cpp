/*
463. Island Perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/
//DFS
class Solution
{
public:
    const static int N=102;
    int ans=0, n, m;
    vector<int>a= {0, 0, 1, -1}, b= {1, -1, 0, 0};
    int check[N][N];
    void call(int i, int j, vector<vector<int>>& grid)
    {
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0)
        {
            ans++;
            return;
        }
        if(check[i][j]==1)
        {
            return;
        }
        check[i][j]=1;
        for(int k=0;k<4;k++)
        {
            call(i+a[k], j+b[k], grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid)
    {
        n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    call(i, j, grid);
                }
            }
        }
        return ans;
    }
};

//Iterative
class Solution
{
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    if(i-1>=0 and grid[i-1][j]==1)
                    {
                        ans-=2;
                    }
                    if(j-1>=0 and grid[i][j-1]==1)
                    {
                        ans-=2;
                    }
                }
            }
        }
        return ans;
    }
};

