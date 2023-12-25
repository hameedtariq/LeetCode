class Solution {
    vector<vector<int>> dv = {{0,1}, {1,0}};
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return rec(--m,--n,0,0,memo);
    }
    int rec(int& m, int& n, int i, int j,vector<vector<int>>& memo){
        if(i==m && j==n) return 1;
        if(i > m || j > n) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = 0;
        for(auto &v: dv){
            memo[i][j] += rec(m,n,i+v[0], j+v[1],memo);
        }
        return memo[i][j];
    }
};