class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        int first = nums[0];
        int second = nums[1];
        for(int i = 2; i < size; i++) {
            int temp = second;
            second = nums[i] + first;
            first = max(temp, first); 
        }
        return max(first,second);
    }
};