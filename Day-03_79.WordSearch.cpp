/*
79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
class Solution {
public:
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool dfs(vector<vector<char>>& board, int i, int j, int pos, string& word) {
        if (pos == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= m || board[i][j] != word[pos])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*'; // Marking as visited
        
        for (const auto& dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (dfs(board, x, y, pos + 1, word))
                return true;
        }
        
        board[i][j] = temp; // Revert back
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};

