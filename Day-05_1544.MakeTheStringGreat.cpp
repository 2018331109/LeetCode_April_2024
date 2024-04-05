/*
1544. Make The String Great
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.
*/
class Solution {
public:
    string makeGood(string s) {
        string st=string(1, s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() and s[i]!=st.back() and (s[i]&31)==(st.back()&31))
            {
                st.pop_back();
            }
            else
            {
                st.push_back(s[i]);
            }
        }
        return st;
        
    }
};
