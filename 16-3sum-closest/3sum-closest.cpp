class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = INT_MAX;
        int diff = INT_MAX;
        for(int i =0; i<nums.size(); i++){ 
            for(int j =i+1; j<nums.size(); j++){
                for(int k =j+1; k<nums.size(); k++){
                    if(abs(target - (nums[i]+nums[j]+nums[k])) < diff){
                        diff = abs(target - (nums[i]+nums[j]+nums[k]));
                        sum = nums[i]+nums[j]+nums[k];
                    }
                }
            } 
        }
        return sum;
    }
};