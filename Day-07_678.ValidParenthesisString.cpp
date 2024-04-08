/*
678. Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open.push(i);
            else if (s[i] == '*')
                star.push(i);
            else {
                if (!open.empty())
                    open.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        while (!open.empty()) {
            if (star.empty() || open.top() > star.top())
                return false;
            else
                open.pop(), star.pop();
        }
        return true;
    }
};
