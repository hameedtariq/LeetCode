class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i =0; i<nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left+1 < n && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(right-1 >= 0 && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }else if(nums[left] + nums[right] < target) {
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};