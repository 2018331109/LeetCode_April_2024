/*
58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
consisting of non-space characters only.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        while(n>=0 and s[n]==' ')
        {
            n--;
        }
        int cnt=0;
        while(n>=0 and s[n]!=' ')
        {
            n--, cnt++;
        }
        return cnt;
        
    }
};
