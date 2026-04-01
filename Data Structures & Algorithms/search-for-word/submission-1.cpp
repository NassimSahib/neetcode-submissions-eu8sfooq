class Solution {
public:
    set<pair<int,int>> path;
    bool dfs(vector<vector<char>>& board, string word, 
            set<pair<int,int>>& path,int r, int c, int i,
            int ROWS, int COLS) {
        bool res;
        if (i == word.size()) return true;
        if ((r < 0 || c < 0) ||
            (r >= ROWS || c >= COLS) ||
            (word[i] != board[r][c]) ||
            (path.contains({r,c}))) {
                return false;
            }
        
        path.insert({r,c});
        res = ((dfs(board,word,path,r+1,c,i+1,ROWS,COLS)) ||
               (dfs(board,word,path,r-1,c,i+1,ROWS,COLS)) ||
               (dfs(board,word,path,r,c+1,i+1,ROWS,COLS)) ||
               (dfs(board,word,path,r,c-1,i+1,ROWS,COLS)));

        path.erase({r,c});
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, path, r, c, 0, ROWS, COLS)) return true;
            }
        }
        return false; 
        
    }
};
