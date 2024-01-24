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
        cout << "Starting: " << pos << endl;
        for(;index < size; index++){
            if(nums[index] > 0 && !pos || nums[index] < 0 && pos) {
                count++;
                pos = !pos;
            }
        }
        return count+1;










        // int i = 1;
        // // skip any duplicates in the start
        // while(i < size && nums[i]-nums[i-1] ==0) i++;
        // if(i == size) return 1;
        // bool pos = (nums[i] - nums[i-1] > 0);
        // int count = 1;
        // int index = i - 1;
        // for(; i< nums.size(); i++){
        //     int diff = nums[i] - nums[index];
        //     if(pos && diff > 0 || !pos && diff < 0){
        //         cout << pos << " ";
        //         count++;
        //         pos = !pos;
        //         index = i;
        //     }
        // }
        // return count;
    }
};