/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Two Pointer:
class Solution
{
public:
    int trap(vector<int>& nums)
    {
        int l=0, r=nums.size()-1;
        int mxl=0, mxr=0, ans=0;
        while(l<=r)
        {
            if(mxl<=mxr)
            {
                if(mxl<=nums[l])
                    mxl=nums[l];
                else
                    ans+=(mxl-nums[l]);
                l++;
            }
            else
            {
                if(mxr<=nums[r])
                    mxr=nums[r];
                else
                    ans+=(mxr-nums[r]);
                r--;
            }
        }
        return ans;
    }
};

//Prefix Calculation: O(n) Space
class Solution
{
public:
    int trap(vector<int>& nums)
    {
        int n=nums.size();
        int ans=0;
        int dp[n];
        dp[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            dp[i]=max(dp[i-1], nums[i]);
        }
        int mx=nums[n-1];
        for(int i=n-2; i>0; i--)
        {
            int mn=min(dp[i-1], mx);
            ans+=max(0, mn-nums[i]);
            mx=max(mx, nums[i]);
        }
        return ans;
    }
};

