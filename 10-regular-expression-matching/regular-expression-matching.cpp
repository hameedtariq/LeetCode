class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<short>> dp(s.size(), vector<short>(p.size(), -1));
        return rec(s,p,0,0, dp);
    }
    bool rec(string& s, string& p, int i, int j, vector<vector<short>>& dp) {
        cout << i <<"," <<j << endl;
        if(i == s.size() && j == p.size()) return true;
        if(i == s.size() && j+1 < p.size() && p[j+1] == '*') {
            return rec(s,p,i,j+2,dp);
        }
        if(j == p.size() || i == s.size()) return false; // pattern has exhausted
        
        if(dp[i][j] != -1) return dp[i][j];
        if( j+1 < p.size() && p[j+1] == '*') { // not a symbol
            if(s[i] == p[j] || p[j] == '.') {
                dp[i][j] = rec(s,p,i+1,j,dp) || rec(s,p,i,j+2,dp);
            }else {
                dp[i][j] = rec(s,p,i,j+2,dp);
            }
        }else if (p[j] == '.') {
            dp[i][j] = rec(s,p,i+1,j+1,dp);
        }else {
            if(p[j] == s[i]) {
                dp[i][j] = rec(s,p,i+1,j+1,dp);
            }else {
                dp[i][j] = false;
            }
        }
        return dp[i][j];
    }
};