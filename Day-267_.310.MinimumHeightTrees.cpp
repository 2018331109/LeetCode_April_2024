/*
310. Minimum Height Trees
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return {0};
        vector<int>graph[n];
        vector<int>deg(n, 0);
        for(auto it:edges)
        {
            int u=it[0], v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        queue<int>q; int left=n; vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1) q.push(i);
        }
        while(!q.empty())
        {
            int sz=q.size(); left-=sz;
            while(sz--)
            {
                int front=q.front(); q.pop();
                if(left==0)
                {
                    ans.push_back(front);
                }
                for(auto it:graph[front])
                {
                    if(--deg[it]==1) q.push(it);
                }
            }
        }
        return ans;
    }
};
