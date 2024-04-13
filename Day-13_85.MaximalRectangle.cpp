/*
85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/
class Solution
{
public:
    int largestRectangleArea(vector<int>& dp)
    {
        int n = dp.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        for (int i = 0; i < n; ++i)
        {
            while (!s1.empty() && dp[s1.top()] >= dp[i])
            {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s2.empty() && dp[s2.top()] >= dp[i])
            {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; ++i)
        {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, dp[i] * width);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int maxArea = 0;
        vector <int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1') dp[j]++;
                else dp[j] = 0;
            }
            int area = largestRectangleArea(dp);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

};



