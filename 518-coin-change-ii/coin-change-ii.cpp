class Solution {
    bool _ = [](){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return false;}();
public:
    int change(int amount, vector<int>& coins) {
        // // unordered_set<int> du;
        // vector<vector<int>> memo(amount+1, vector<int>(coins.size(),-1));
        // return rec(amount,coins,0,memo);
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins)
            for (int i = c; i <= amount; ++i)
                dp[i] += dp[i - c];
        return dp[amount];
    }
    int rec(int amount, vector<int>& coins,int start,vector<vector<int>>& memo){
        if(start == 0) return (amount%coins[0] == 0);
        if(amount == 0) return 1;
        if(amount < 0) return 0;   
        if(start >= coins.size()) return 0;
        if(memo[amount][start] != -1) return memo[amount][start];
        int include = rec(amount-coins[start],coins,start,memo);
        int exclude = rec(amount,coins,start+1,memo);
        memo[amount][start] = include + exclude;
        return memo[amount][start];
    }
};