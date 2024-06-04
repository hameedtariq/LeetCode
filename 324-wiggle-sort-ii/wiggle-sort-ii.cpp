class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> count(5001,0);

        for(auto &a: nums){
            count[a]++;
        }
        int j = 5000;
        // fill in odd pos
        for(int i =1; i< nums.size(); i+=2) {
            while(j >=0 && count[j] == 0) j--; // find the largest number
            nums[i] = j;
            count[j]--;
        }
        // fill in even pos
        for(int i = 0; i< nums.size(); i+=2) {
            while(j >=0 && count[j] == 0) j--; // find the largest number
            nums[i] = j;
            count[j]--;
        }
    }
};