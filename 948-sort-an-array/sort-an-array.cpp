class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        
        merge(nums, left, mid, right);        
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        int l = left;
        int r = mid+1;
        vector<int> temp(right-left+1);
        int k = 0;
        // merge sorted sub arrays into new array.
        while(l <= mid && r <= right){
            if(nums[l] <= nums[r]) {
                temp[k++] = nums[l++];
            }else {
                temp[k++] = nums[r++];
            }
        }
        while(l <= mid){
            temp[k++] = nums[l++];
        }
        while(r <= right){
            temp[k++] = nums[r++];
        }
        // fill back sorted portion into array.
        for(int i = 0; i<temp.size(); i++) {
            nums[left+i] = temp[i];
        }
    }
};