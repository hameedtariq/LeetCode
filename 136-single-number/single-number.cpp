class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &n : nums){
            m[n]++;
        }
        for(auto& [k,v] : m) {
            if (v == 1) return k;
        }

        return -1;
    }
};