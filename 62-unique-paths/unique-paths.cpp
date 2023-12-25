class Solution {
    // vector<vector<int>> dv = {{0,1}, {1,0}};
    vector<vector<int>> dv = {{0,-1}, {-1,0}};
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

        // return rec(--m,--n,0,0,memo);

    }
    // int rec(int& m, int& n, int i, int j,vector<vector<int>>& memo){
    //     if(i==m && j==n) return 1;
    //     if(i > m || j > n) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     memo[i][j] = 0;
    //     for(auto &v: dv){
    //         memo[i][j] += rec(m,n,i+v[0], j+v[1],memo);
    //     }
    //     return memo[i][j];
    // }
};