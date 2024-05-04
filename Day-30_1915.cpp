/*
1915. Number of Wonderful Substrings
A wonderful string is a string where at most one letter appears an odd number of times.

    For example, "ccjjc" and "abab" are wonderful, but "ab" is not.

Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.
*/
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long cnt=0, total=0;
        vector<long long>v(1024, 0);
        v[0]=1;
        for(auto it:word)
        {
            long long ind=it-'a';
            total^=1<<ind;
            cnt+=v[total];
            v[total]++;
            for(long long i=0;i<10;i++)
            {
                long long ind=total^(1<<i);
                cnt+=v[ind];
            }
        }
        return cnt;
    }
};

