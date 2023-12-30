class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(),vector<int>(t.size(), -1));
        return rec(s,t,0,0,memo);
    }
    int rec(string& s, string& t, int i, int j,vector<vector<int>> &memo){
        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(s[i] == t[j]) {
            ans += rec(s,t, i+1,j+1,memo);
        }
        ans += rec(s,t,i+1,j,memo);
        return memo[i][j] = ans;
    }
};