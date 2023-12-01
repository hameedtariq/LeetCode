class Solution {
private:
    int m;
    int n;
    const vector<vector<int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        
        for (const auto& direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            
            if (isValid(grid, nextRow, nextCol) && grid[nextRow][nextCol] == '1')
                dfs(grid, nextRow, nextCol);
        }
    }
    
    bool isValid(vector<vector<char>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};