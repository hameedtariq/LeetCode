#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_global = nums[0];
        int max_local = nums[0];
        for(int i =1; i<nums.size(); i++) {
            max_local = max(nums[i], nums[i]+max_local);
            max_global = max(max_local, max_global);
        }
        return max_global;
    }
};