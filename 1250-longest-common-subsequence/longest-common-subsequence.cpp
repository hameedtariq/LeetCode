bool _ = []() {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return false;}();
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size(), n2 = t2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i =0; i<=n1; i++){
            dp[i][0] = 0;
        }
        for(int i =0; i<=n2; i++){
            dp[0][i] = 0;
        }
        for(int i =1; i<=n1; i++){
            for(int j =1; j<=n2; j++){
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};