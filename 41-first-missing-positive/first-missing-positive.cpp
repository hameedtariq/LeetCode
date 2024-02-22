class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &n: nums){
            if(n > 0)
                s.insert(n);
        }
        for(int i =1; i <= nums.size(); i++) {
            if(s.find(i) == s.end()) return i;
        }
        return nums.size()+1;
    }

};