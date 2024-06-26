/*
1992. Find All Groups of Farmland
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
*/
class Solution {
public:
    int n, m;
    void call(vector<vector<int>>& land, int i, int j, int &r, int &c)
    {
        if(i>=n or j>=m or land[i][j]!=1) return;
        land[i][j]=-1;
        r=max(i, r), c=max(c, j);
        call(land, i+1, j, r, c);
        call(land, i, j+1, r, c);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(), m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                    int r=0, c=0;
                    call(land, i, j, r, c);
                    ans.push_back({i, j, r, c});
                }
            }
        }
        return ans;
    }
};
