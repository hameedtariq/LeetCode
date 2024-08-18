class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) return;
        int p = 0, q = 0, r = nums.size()-1;
        while(p < nums.size() && nums[p] == 0) p++;
        q = p;
        while(r >= 0 && nums[r] == 2) r--;
        if(p == nums.size() || r < 0) {
            return;
        }
        
        while(q <= r) {
            if(nums[q] == 1) {
                q++;
            }else if(nums[q] == 0) {
                swap(nums[p], nums[q]);
                if(p == q) {q++; q++;}
                else p++;
            }else {
                swap(nums[q], nums[r]);
                r--;
            }
        }
        
    }
};