class Solution {
public:
    int uniquePaths(int m, int n) {
        //return uniquePathsTopDown(m, n);
        return uniquePathsBottomUp(m, n);
    }
    
    int uniquePathsTopDown(int m, int n) {
        this->m = m;
        this->n = n;
        this->cache = vector(m, vector<int>(n, 0));
        return dp(m-1, n-1);
    }
    
    int m;
    int n;
    vector<vector<int>> cache;
    int dp(int row, int col) {
        if (row == 0 && col == 0) {
            return 1;
        }
        
        if (cache[row][col] == 0) {
            int nbPaths = 0;
            if (row > 0) {
                nbPaths += dp(row-1, col);
            }
            if (col > 0) {
                nbPaths += dp(row, col-1);
            } 
            cache[row][col] = nbPaths;
        }
        
        return cache[row][col];    
    }
    
    int uniquePathsBottomUp(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, 0));
        cache[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nbPaths = 0;
                if (i > 0) {
                    nbPaths += cache[i-1][j];
                }
                if (j > 0) {
                    nbPaths += cache[i][j-1];
                }
                cache[i][j] = nbPaths;
            }
        }

        return cache[m-1][n-1];
    }
};