class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> ss;

        sort(nums.begin(), nums.end());

        for(auto&n: nums) {
            ss.insert(n);
        }
        int length = 1;
        
        for(auto&n: nums) {
            long long x = pow(n,2);
            int l = 1;
            while(ss.find(x) != ss.end()) {
                ss.erase(x);
                l++;
                x = pow(x, 2);
            }
            length = max(length, l);
        }

        return length == 1 ? -1 : length;
    }
};