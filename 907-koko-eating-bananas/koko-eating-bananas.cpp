
typedef unsigned long long ull;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low < high){
            int mid = low + ((high-low)>>2);
            ull cnt = 0;
            for(int i = 0; i < piles.size(); i++){
                cnt += (piles[i]+mid-1)/mid;
            }
            if(cnt > h){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid;
            }
        }
        return ans;
    }
};