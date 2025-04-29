class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = 10000;
        vector<int> arr(2 * num + 1, 0);
        for(auto x: nums) {
            arr[x+num]++;
        }
        int k = 0;
        for(int i =0; i<2 * num + 1; i++) {
            int l = 0;
            while(arr[i] > 0 && l < 2) {
                nums[k++] = i-num;
                l++;
                arr[i]--;
            }
        }
        return k;
    }
};