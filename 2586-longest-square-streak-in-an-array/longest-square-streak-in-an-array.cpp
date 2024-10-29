class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> ss;

        for(auto&n: nums) {
            ss.insert(n);
        }
        int length = 1;
        
        for(auto&n: nums) {
            long long x = pow(n,2);
            int l = 1;
            while(ss.find(x) != ss.end()) {
                l++;
                x = pow(x, 2);
            }
            length = max(length, l);
        }

        return length == 1 ? -1 : length;
    }
};