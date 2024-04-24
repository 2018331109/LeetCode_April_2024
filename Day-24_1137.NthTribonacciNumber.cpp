/*
1137. N-th Tribonacci Number
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/
class Solution {
public:
    unordered_map<int, int>mp;
    int call(int n)
    {
        if(n==0) return mp[n]=0;
        if(n==1 or n==2) return mp[n]=1;
        if(mp[n]) return mp[n];
        return mp[n]=call(n-1)+call(n-2)+call(n-3);
    }
    int tribonacci(int n) {
        return call(n);
    }
};
