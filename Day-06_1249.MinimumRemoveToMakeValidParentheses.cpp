/*
1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

*/
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n=s.size();
        int open=0, close=0, f=0;
        for(auto it:s)
        { 
            if(it=='(') open++, f++;
            else if(it==')' and f>0) close++, f--;
        }
        open=close;
        string ans="";
        for(auto it:s)
        {
            if(it!='(' and it!=')')
            {
                ans+=it;
                continue;
            }
            if(it=='(' and open>0)
            {
                ans+=it;
                open--;
                continue;
            }
            if(it==')' and close>open)
            {
                ans+=it;
                close--;
                continue;
            }
        }
        return ans;
    }
};

