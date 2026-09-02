class Solution {
public:
    void dfs(int r, int c,
            set<pair<int,int>>& visited, 
            const vector<vector<int>>& heights,
            int prevHeight) {
            if (r < 0 || c < 0 ||
                r >= heights.size()|| c >= heights[0].size() ||                   visited.contains({r,c}) ||
                heights[r][c] < prevHeight) return;

            visited.insert({r,c});
            
            dfs(r + 1, c, visited, heights, heights[r][c]);
            dfs(r - 1, c, visited, heights, heights[r][c]);
            dfs(r, c + 1, visited, heights, heights[r][c]);
            dfs(r, c - 1, visited, heights, heights[r][c]);

        }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        std::set<pair<int,int>> pacific;
        std::set<pair<int,int>> atlantic;

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pacific, heights, heights[0][c]);
            dfs(ROWS - 1, c, atlantic,  heights, heights[ROWS - 1][c]);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pacific,  heights, heights[r][0]);
            dfs(r, COLS - 1, atlantic,  heights, heights[r][COLS - 1]);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pacific.contains({r, c}) && atlantic.contains({r, c})) {
                    res.push_back({r,c});
                }
            }
        }

        return res;

        
    }
};
