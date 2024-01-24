class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        // base cases
        if(size == 1){
            return 1;
        }
        if(size == 2){
            if(nums[0] != nums[1]){
                return 2;
            }else {
                return 1;
            }
        }
        // actual code
        for(int i =1; i<size;i++){
            nums[i-1] = nums[i] - nums[i-1];
        };
        size--;
        int index = 0;
        int count = 1;
        while(index < size && nums[index] == 0) index++; // skip zeros
        if(index == size) return count;
        bool pos = (nums[index] > 0); // false
        for(;index < size; index++){
            if(nums[index] > 0 && !pos || nums[index] < 0 && pos) {
                count++;
                pos = !pos;
            }
        }
        return count+1;
    }
};