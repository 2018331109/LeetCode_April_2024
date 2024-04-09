/*
2073. Time Needed to Buy Tickets
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<=k)
                ans+=min(nums[i], nums[k]);
            else
                ans+=min(nums[k]-1, nums[i]);
        }
        return ans;
    }
};
