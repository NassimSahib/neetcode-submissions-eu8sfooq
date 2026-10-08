#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        auto dfs = [&](auto& self, int r, int c, vector<vector<bool>>& ocean, int prevHeight) -> void {
            if (r < 0 || r >= m || c < 0 || c >= n || ocean[r][c] || heights[r][c] < prevHeight) {
                return;
            }
            
            ocean[r][c] = true;
            
            self(self, r + 1, c, ocean, heights[r][c]);
            self(self, r - 1, c, ocean, heights[r][c]);
            self(self, r, c + 1, ocean, heights[r][c]);
            self(self, r, c - 1, ocean, heights[r][c]);
        };
        
        for (int c = 0; c < n; ++c) {
            dfs(dfs, 0, c, pacific, heights[0][c]);         
            dfs(dfs, m - 1, c, atlantic, heights[m - 1][c]); 
        }
        
        for (int r = 0; r < m; ++r) {
            dfs(dfs, r, 0, pacific, heights[r][0]);         
            dfs(dfs, r, n - 1, atlantic, heights[r][n - 1]);  
        }
        
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};

