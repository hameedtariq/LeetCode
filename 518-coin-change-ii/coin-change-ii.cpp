#include <vector>
#include <climits>

class Solution {
public:
    int64_t solve(vector<int>& coins, int target, int index, vector<vector<int64_t>>& dp) {
        if (target == 0) {
            return 1;
        }
        if (index == coins.size()) {
            return 0;
        }
        if (target < 0) {
            return 0;
        }

        if (dp[target][index] != -1) {
            return dp[target][index];
        }

        int64_t include = solve(coins, target - coins[index], index, dp);
        int64_t exclude = solve(coins, target, index + 1, dp);

        dp[target][index] = include + exclude;
        return dp[target][index];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int64_t>> dp(amount + 1, vector<int64_t>(coins.size() + 1, -1));
        int64_t ways = solve(coins, amount, 0, dp);

        // Check if the result fits within the range of a 32-bit signed integer
        if (ways > INT_MAX) {
            return INT_MAX;
        }

        return static_cast<int>(ways);
    }
};