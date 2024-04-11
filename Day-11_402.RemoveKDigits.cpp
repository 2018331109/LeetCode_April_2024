/*
402. Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/
class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        int n=s.size();
        string ans;
        stack<char>st;
         
        for(auto it:s)
        {
            while(!st.empty() and st.top()>it and k)
                st.pop(), k--;
                
            st.push(it);
        }
        while(!st.empty() and k)
            st.pop(), k--;
        
        while(!st.empty())
            ans+=st.top(), st.pop();
        
        reverse(ans.begin(), ans.end());
       
        size_t pos=ans.find_first_not_of('0');

        if(pos==string::npos)
            ans="0";
        else 
            ans=ans.substr(pos);

        return ans;
    }
};

