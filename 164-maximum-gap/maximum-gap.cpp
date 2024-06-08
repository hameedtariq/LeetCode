class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        set<int> numSet;
        for(auto &n: nums) {
            numSet.insert(n);
        } 
        int i =0;
        int maxGap = 0;
        int prevVal = -1;
        for(auto & num: numSet) {
            if(prevVal == -1) {
                prevVal = num;
                continue;
            }
            maxGap = max(maxGap, num - prevVal);
            prevVal = num;
        }

        return maxGap;
    }
};