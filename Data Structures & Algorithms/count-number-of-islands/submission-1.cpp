class Solution {
public:
    void dfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') return;

        grid[r][c] = '0';
        dfs(r+1,c,rows,cols,grid);
        dfs(r,c+1,rows,cols,grid);
        dfs(r-1,c,rows,cols,grid);
        dfs(r,c-1,rows,cols,grid);
        return;

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int num_islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(r,c,rows,cols,grid);
                }
            }
        }
        return num_islands;
        
    }
};
