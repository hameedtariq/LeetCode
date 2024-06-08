class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        long long sum = (long)nums[0] + nums[1] + nums[2] + nums[3];
        if(sum > target) return ans;

        int i =0; 
        while(i<nums.size()) {
            int j =i+1;
            while(j<nums.size()) {
                int left = j+1;
                int right = nums.size()-1;
                while(left < right) {
                    sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        left++;
                    }else if(sum < target) {
                        while(left < right && nums[left] == nums[left+1]) left++;
                        left++;
                    }else {
                        while(left < right && nums[right] == nums[right-1]) right--;
                        right--;
                    }
                }
                while(j < nums.size()-1 && nums[j] == nums[j+1]) j++;
                j++;
            }
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};