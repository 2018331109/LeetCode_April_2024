/*
514. Freedom Trail
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

    You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
    If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.
*/

//Top Down DP:
class Solution
{
public:
    int n, k;
    int memo[101][101];
    int call(int u, int v)
    {
        return min(abs(u-v), n-abs(u-v));
    }
    int solve(int ri, int ki, string& ring, string& key)
    {
        if(ki==k)
        {
            return 0;
        }
        if(memo[ri][ki] != -1)
        {
            return memo[ri][ki];
        }
        int res=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(ring[i]==key[ki])
            {
                int steps=1+call(ri, i)+solve(i, ki+1, ring, key);
                res=min(res, steps);
            }
        }
        return memo[ri][ki]=res;
    }
    int findRotateSteps(string ring, string key)
    {
        n=ring.size(), k=key.size();
        memset(memo, -1, sizeof(memo));
        int ans=solve(0, 0, ring, key);
        return ans;

    }
};

//Bottom Up DP:
class Solution
{
public:
    int n, m, memo[101][101];
    int call(int u, int v)
    {
        return min(abs(u-v), n-abs(u-v));
    }
    int findRotateSteps(string ring, string key)
    {
        n=ring.size(), m=key.size();
        memset(memo, 0, sizeof(memo));
        for(int j=m-1; j>=0; j--)
        {
            for(int i=0; i<n; i++)
            {
                int res=INT_MAX;
                for(int k=0; k<n; k++)
                {
                    if(ring[k]==key[j])
                    {
                        int steps=1+call(i, k)+memo[k][j+1];
                        res=min(res, steps);
                    }
                }
                memo[i][j]=res;
            }
        }
        return memo[0][0];
    }
};

