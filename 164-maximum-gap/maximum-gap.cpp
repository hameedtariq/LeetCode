class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        map<int,int> count;
        for(auto &n: nums) {
            count[n]++;
        } 
        int i =0;
        for(auto & [key, val]: count) {
            while(val) {
                nums[i++] = key;
                val--;
            }
        }
        int maxGap = INT_MIN;
        for(int i =1; i<nums.size(); i++) {
            maxGap = max(nums[i] - nums[i-1], maxGap);
        }
        return maxGap;
    }
};