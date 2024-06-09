
bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        
        if (maxNum == minNum) return 0;
        
        int gap = (maxNum - minNum) / (n - 1);
        if ((maxNum - minNum) % (n - 1) != 0) {
            gap++;
        }
        
        std::vector<int> minArr(n, INT_MAX);
        std::vector<int> maxArr(n, INT_MIN);
        
        for (int i = 0; i < n; i++) {
            int bkt = (nums[i] - minNum) / gap;
            minArr[bkt] = std::min(minArr[bkt], nums[i]);
            maxArr[bkt] = std::max(maxArr[bkt], nums[i]);
        }
        
        int ans = 0;
        int prev = maxArr[0];
        
        for (int i = 1; i < n; i++) {
            if (minArr[i] == INT_MAX) continue;
            ans = std::max(ans, minArr[i] - prev);
            prev = maxArr[i];
        }
        
        return ans;
    }
};