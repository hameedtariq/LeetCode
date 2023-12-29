class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        wcin.tie(nullptr);
        cerr.tie(nullptr);
        wcerr.tie(nullptr);
        clog.tie(nullptr);
        wclog.tie(nullptr);
    }

    int longest(const vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();   
        if (memo[i * n + j] != -1) {
            return memo[i * n + j];
        }
        int best = 0;
        int cij = matrix[i][j];
        for (int k = -1; k <= 1; ++k) {
            if (i + k < 0 || i + k >= m) continue;
            for (int l = -1; l <= 1; ++l) {
                if (j + l < 0 || j + l >= n || std::abs(k + l) != 1) continue;
                if (cij < matrix[i + k][j + l]) {
                    best = std::max(best, longest(matrix, i + k, j + l) + 1);
                }
            }
        }
        memo[i * n + j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memo.resize(m * n, -1);
        int best = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                best = std::max(best, longest(matrix, i, j) + 1);
            }
        }
        return best;
    }

    std::vector<int> memo;
};