class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalSum = nums[0];
        int localSum = nums[0];
        for(int i =1; i<nums.size(); i++) {
            localSum = max(localSum+nums[i],nums[i]);
            globalSum = max(localSum, globalSum);
        }
        return globalSum;
    }
};