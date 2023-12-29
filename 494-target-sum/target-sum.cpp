class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>((target+1) + 2000,-1));
        return rec(nums,target, 0, memo);
    }
    int rec(vector<int>& nums, int target, int i, vector<vector<int>>& memo){
        if(i == nums.size() && target == 0) return 1;
        if(i == nums.size()) return 0;
        if(memo[i][target+1000] != -1) return memo[i][target+1000];
        int plus = rec(nums,target-nums[i], i+1,memo);
        int minus = rec(nums,target+nums[i], i+1, memo);
        memo[i][target+1000] = plus + minus;
        return memo[i][target+1000];
    }
};