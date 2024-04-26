class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return minPath(grid, 0,-1, n, dp);
    }
    int minPath(vector<vector<int>>& grid, int row, int prevCol, int &n, vector<vector<int>>& dp) {
        if(row >= n || row < 0 ) return 0;
        if(dp[row][prevCol+1] != -1) return dp[row][prevCol+1];
        dp[row][prevCol+1] = INT_MAX;
        for(int i =0; i<n;i++) {
            if(i != prevCol)
                dp[row][prevCol+1] = min(dp[row][prevCol+1], grid[row][i] + minPath(grid, row+1, i, n,dp));
        }
        return dp[row][prevCol+1];
    }
};