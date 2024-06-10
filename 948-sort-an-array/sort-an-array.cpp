class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int pivot = (rand() % (right-left+1)) + left;
        swap(nums[pivot], nums[right]);
        int l = left;
        int r = right-1;
        while(l <= r) {
            if(nums[l] <= nums[right]) {
                l++;
            }else if(nums[r] >= nums[right]) {
                r--;
            }else {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        swap(nums[l], nums[right]);
        quickSort(nums, left, l-1);
        quickSort(nums, l+1, right);
    }
};