bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1) return 1;
        vector<vector<int>> memo(2,vector<int>(n,0));
        for(int i =1; i<=n; i++){
            memo[1][n-i] = 1;
        }
        memo[0][n-1] = 1;
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                memo[0][j] = memo[1][j] + memo[0][j+1]; 
            }
            for(int i =1; i<=n; i++){
                memo[1][n-i] = memo[0][n-i];
            }
        }
        return memo[0][0];
    }
};