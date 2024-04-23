/*
752. Open the Lock
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
*/
class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string>dead(deadends.begin(), deadends.end());
        queue<pair<string, int>>q;
        if(dead.find("0000")==dead.end())
        {
            q.push({"0000", 0});
            dead.insert("0000");
        }
        while(!q.empty())
        {
            pair<string, int>current=q.front(); q.pop();
            string s=current.first;
            int cnt=current.second;
            if(s==target) return cnt;
            for(int i=0; i<4; i++)
            {
                string t1=s.substr(0, i)+to_string((s[i]-'0'+1+10)%10)+s.substr(i+1);
                string t2=s.substr(0, i)+to_string((s[i]-'0'-1+10)%10)+s.substr(i+1);
                if(dead.find(t1)==dead.end())
                {
                    q.push({t1, cnt+1});
                    dead.insert(t1);
                }
                if(dead.find(t2)==dead.end())
                {
                    q.push({t2, cnt+1});
                    dead.insert(t2);
                }
            }
        }
        return -1;
    }
};

