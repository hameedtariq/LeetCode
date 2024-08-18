class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int b = 0;
        int s = 1;

        while(s < prices.size()) {
            if(prices[b] > prices[s]) {
                b++;
            }else{
                maxProf = max(maxProf, prices[s] - prices[b]);
                s++;
            }
        }
        return maxProf;
    }
};