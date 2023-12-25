class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(2, vector<int>(n, -1));
        return (rec(prices,-1,0, memo, n));
    }
    int rec(vector<int>& prices, int buy,int i,vector<vector<int>>& memo, int& total){
        if(i >= total) return 0;
        if(memo[buy != -1][i] != -1)
           return memo[buy != -1][i];
        if(memo[buy != -1][i] != -1) return memo[buy != -1][i];
        if(buy == -1){ // buying state
            memo[buy != -1][i] = max(rec(prices,i,i+1, memo, total)-prices[i], rec(prices,-1,i+1, memo, total));
        }else { // selling state
            memo[buy != -1][i] = max((rec(prices,-1,i+2, memo, total) + (prices[i])),rec(prices,buy,i+1, memo, total));
        }
        
        return memo[buy != -1][i];
    }
};