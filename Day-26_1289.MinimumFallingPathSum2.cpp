/*
1289. Minimum Falling Path Sum II
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.
*/
//Recursive:
class Solution
{
public:
    int n;
    int memo[202][202];
    int call(int i, int j, vector<vector<int>>& grid)
    {
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(i==n-1)
        {
            return grid[i][j];
        }
        int res=INT_MAX;
        for(int k=0; k<n; k++)
        {
            if(k!=j)
            {
                res=min(res, call(i+1, k, grid));
            }
        }

        return memo[i][j]=res+grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        n=grid.size();
        memset(memo, -1, sizeof(memo));
        int ans=INT_MAX;

        for(int col=0; col<n; col++)
        {
            ans=min(ans, call(0, col, grid));
        }
        return ans;
    }
};

//Optimized Space: Bottom Up
class Solution
{
public:
    int n, memo[202][202], ans=INT_MAX;
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        n=grid.size();
        memset(memo, 0, sizeof(memo));
        for(int j=0;j<n;j++)
        {
            memo[n-1][j]=grid[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int res=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                    {
                        res=min(res, memo[i+1][k]);
                    }
                }
                memo[i][j]=res+grid[i][j];
            }
        }
        for(int j=0;j<n;j++)
        {
            ans=min(ans, memo[0][j]);
        }
        return ans;
    }
};

//Optimized: Time
class Solution
{
public:
    int n, memo[202][202], ans=INT_MAX;
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        n=grid.size();
        memset(memo, 0, sizeof(memo));
        int mn1=-1, mn2=-1;
        for(int j=0;j<n;j++)
        {
            memo[n-1][j]=grid[n-1][j];
            if(mn1==-1 or(memo[n-1][j]<=memo[n-1][mn1]))
            {
                mn2=mn1, mn1=j;
            }
            else if(mn2==-1 or (memo[n-1][j]<memo[n-1][j]))
            {
                mn2=j;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            int c1=-1, c2=-1;
            for(int j=0;j<n;j++)
            {
                 if(j!=mn1)
                 {
                    memo[i][j]=memo[i+1][mn1]+grid[i][j];
                 }
                 else
                 {
                    memo[i][j]=memo[i+1][mn2]+grid[i][j];
                 }
                 if(c1==-1 or (memo[i][j]<=memo[i][c1]))
                 {
                    c2=c1, c1=j;
                 }
                 else if(c2==-1 or (memo[i][j]<memo[i][c2]))
                 {
                    c2=j;
                 }
            }
            mn1=c1, mn2=c2;
        }
       return memo[0][mn1];
    }
};

//Optimized: Time and Space
class Solution
{
public:
    int n;
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        n=grid.size();
        int mn1=-1, mn2=-1, mv1=0, mv2=0;
        for(int j=0; j<n; j++)
        {
            if(mn1==-1 or(grid[n-1][j]<=mv1))
            {
                mn2=mn1, mn1=j, mv2=mv1, mv1=grid[n-1][j];
            }
            else if(mn2==-1 or (grid[n-1][j]<grid[n-1][j]))
            {
                mn2=j, mv2=grid[n-1][j];
            }
        }
        for(int i=n-2; i>=0; i--)
        {
            int c1=-1, c2=-1, cv1=-1, cv2=-1, res=INT_MAX;
            for(int j=0; j<n; j++)
            {
                if(j!=mn1)
                {
                    res=grid[i][j]+mv1;
                }
                else
                {
                    res=grid[i][j]+mv2;
                }
                if(c1==-1 or (res<cv1))
                {
                    c2=c1, cv2=cv1, c1=j, cv1=res;
                }
                else if(c2==-1 or (res<cv2))
                {
                    c2=j, cv2=res;
                }

            }
            mn1=c1, mn2=c2, mv1=cv1, mv2=cv2;
        }
        return mv1;
    }
};

