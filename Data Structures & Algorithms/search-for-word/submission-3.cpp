class Solution {
public:
    set<pair<int,int>> path;

    bool dfs(vector<vector<char>>& board, string word,
             set<pair<int,int>>& path, int r, int c,
             int i, int rows, int cols) {
                bool res;

                if (i == word.size()) return true;

                if (r < 0 || c < 0 ||
                    r >= rows || c >= cols ||
                    board[r][c] != word[i] || path.contains({r,c})) return false;
                    
                path.insert({r,c});
                res = (((dfs(board, word, path, r+1, c, i+1, rows, cols)) ||
                        (dfs(board, word, path, r-1, c, i+1, rows, cols)) ||
                        (dfs(board, word, path, r, c+1, i+1, rows, cols)) ||
                        (dfs(board, word, path, r, c-1, i+1, rows, cols))));

                path.erase({r,c});
                return res;

            }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                path.clear();
                if (dfs(board, word, path, r, c, 0, rows, cols)) return true;
            }
        }

        return false;
                
        
    }
};
