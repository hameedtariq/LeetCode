class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(),-1));
        return rec(word1,word2,0,0, dp);
    }
    int rec(string& w1, string& w2, int i, int j,vector<vector<int>>& dp) {

        if(i == w1.size() && j == w2.size()) return 0;
        if(i == w1.size()) {
            // insert
            return w2.size() - j;
        }
        if(j == w2.size()) {
            // insert
            return w1.size() - i;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i] == w2[j]) {
            return rec(w1, w2, i+1, j+1,dp);
        }

        int insert = rec(w1,w2,i,j+1,dp);
        int del = rec(w1,w2,i+1,j,dp);
        int replace = rec(w1, w2, i+1, j+1,dp);
        return dp[i][j] = min({insert,del,replace}) + 1;  
    }
};