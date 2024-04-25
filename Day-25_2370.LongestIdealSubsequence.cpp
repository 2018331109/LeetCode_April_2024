/*
2370. Longest Ideal Subsequence
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

    t is a subsequence of the string s.
    The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.

Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
*/
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int ans=0;
        vector<int>mp(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            char left=max(0, s[i]-k-'a');
            char right=min(25, s[i]+k-'a');
            int mx=0;
            while(left<=right)
            {
                mx=max(mx, mp[left]);
                left++;
            }
            mp[s[i]-'a']=mx+1;
            ans=max(ans, mp[s[i]-'a']);
        }
        return ans;
    }
};
