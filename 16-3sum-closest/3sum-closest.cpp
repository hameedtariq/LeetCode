class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];  
        sort(nums.begin(), nums.end());
        int left, right,closestSum = nums[0] + nums[1] + nums[2];
        for(int i =0; i< nums.size(); i++) {
            left = i+1;
            right = nums.size()-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target-sum) < abs(target-closestSum)) {
                    closestSum = sum;
                }

                if(target-sum < 0) {
                    right--;
                }else {
                    left++;
                }
            }
            
        }
        return closestSum;
    }
};