bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,0));
        for(int i =1; i<=m; i++){
            memo[m-i][n-1] = 1;
        }
        for(int i =1; i<=n; i++){
            memo[m-1][n-i] = 1;
        }
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                memo[i][j] = memo[i+1][j] + memo[i][j+1]; 
            }
        }
        return memo[0][0];
    }
};