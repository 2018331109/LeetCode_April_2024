/*
1971. Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/
class Solution {
public:
    bool dfs(int s, int d, vector<vector<int>>& graph, vector<bool>& visited) {
        if (s == d) return true;
        visited[s] = true;
        for (auto neighbor : graph[s]) {
            if (!visited[neighbor] && dfs(neighbor, d, graph, visited)) {
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        return dfs(s, d, graph, visited);
    }
};

