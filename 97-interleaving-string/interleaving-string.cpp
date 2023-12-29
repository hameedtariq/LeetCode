bool _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return false;}();
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!= s3.size()) return false;
        vector<vector<short>> memo(s1.size()+1,vector<short>(s2.size()+1, -1));
        return rec(s1,s2,s3, 0,0,memo); 
    }
    bool rec(string &s1, string &s2, string &s3, int i, int j, vector<vector<short>> & memo){
        if(i == s1.size() && j == s2.size()) return true;
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = false;
        if(i < s1.size()) {
            if(s1[i] == s3[i+j]){
                memo[i][j]  = memo[i][j] || rec(s1,s2,s3, i+1, j,memo);
            }
        }
        if(j < s2.size()) {
            if(s2[j] == s3[i+j]){
                memo[i][j]  = memo[i][j] || rec(s1,s2,s3, i, j+1,memo);
            }
        }
        return memo[i][j];
    }
};