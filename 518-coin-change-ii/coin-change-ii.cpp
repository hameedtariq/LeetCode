class Solution {
    bool _ = [](){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return false;}();
public:
    int change(int amount, vector<int>& coins) {
        // unordered_set<int> du;
        vector<vector<int>> memo(amount+1, vector<int>(coins.size(),-1));
        return rec(amount,coins,0,memo);
    }
    int rec(int amount, vector<int>& coins,int start,vector<vector<int>>& memo){
        if(amount == 0) return 1;
        if(amount < 0) return 0;   
        if(memo[amount][start] != -1) return memo[amount][start];     
        memo[amount][start] = 0;
        for(int i = start; i < coins.size(); i++){
            memo[amount][start] += rec(amount-coins[i],coins,i,memo);
        }
        return memo[amount][start];
    }
};