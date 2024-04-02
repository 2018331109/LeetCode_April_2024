/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int>ss(128, 0), tt(128, 0);
        for(int i=0;i<s.size();i++)
        {
            if(ss[s[i]] != tt[t[i]])
            {
                return false;
            }
            ss[s[i]]=i+1, tt[t[i]]=i+1;
        }
        return true;
    }
};

