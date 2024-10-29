const int BS_SIZE = 100'001;
bitset<BS_SIZE> bs;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int start = INT_MAX;
        for(int num : nums) {
            bs[num] = 1;
            start = min(start, num);
        }

        int ans = -1;
        
        for(int i = start; i != BS_SIZE; i = bs._Find_next(i)) {
            bs[i] = 0; // auto-reset
            if(i > 316) continue;
            int num = i * i;
            if(!bs[num]) continue;
            bs[num] = 0;
            int j = 2;
            while(num <= 316) { // 316 = floor(sqrt(1e5)), where 1e5 is max constraint
                num *= num;
                if(bs[num]) {
                    j++, bs[num] = 0; // auto-reset
                }else {
                    break;
                }
            }

            ans = max(ans, j);
        }


        return ans;
    }
};