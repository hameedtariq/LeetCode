class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr(205, 0);
        for(auto x: nums) {
            arr[x+100]++;
        }
        int k = 0;
        for(int i =0; i<205; i++) {
            if(arr[i] != 0) {
                nums[k++] = i-100;
            }
        }
        return k;
    }
};