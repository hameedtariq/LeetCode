class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use hashmap for checking if a number exists.
        if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int lcs = 0;
        for(int i = 0; i< nums.size(); i++) {
            if(s.find(nums[i]-1) != s.end()) continue; // not start of sequence!
            int l = 1;
            int j = nums[i]+1;

            while(s.find(j) != s.end()) {
                j++;
                l++;
            }
            lcs = max(lcs, l);
        }
        return lcs;
    }
};