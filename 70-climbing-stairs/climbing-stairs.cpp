class Solution {
    vector<int> memo = vector<int>(46, -1);
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(memo[n] != -1) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};