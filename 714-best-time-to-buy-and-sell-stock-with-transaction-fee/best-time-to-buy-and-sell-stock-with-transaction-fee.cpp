class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return (rec(prices, fee, 0, 0,memo));
    }
    int rec(vector<int>& prices, int& fee, bool buy, int i, vector<vector<int>>& memo){
        if(i == prices.size()) return 0;
        if(memo[i][buy] != -1) return memo[i][buy];
        int profit;
        if(!buy){ // not purchased
            profit = max(rec(prices, fee, 1, i+1,memo) - prices[i],rec(prices, fee, 0, i+1,memo));
        }else { // already purchased
           profit = max(rec(prices, fee, 0, i+1,memo)+(prices[i]-fee), rec(prices, fee, 1, i+1,memo));
        }
        return memo[i][buy] = profit;
    }
};