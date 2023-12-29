class Solution {
    vector<vector<int>> dv = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int path = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> memo(m,vector<int>(n,-1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                path = max(path, dfs(matrix,visited,i,j,-1, memo));
            }
        }
        return path;
    }
    int dfs(vector<vector<int>>& m, vector<vector<bool>>& v, int i,int j, int prev, vector<vector<int>> &memo) {
        if(i >= m.size() || i < 0 || j >= m[0].size() || j < 0 || v[i][j]) {
            return 0;
        }
        if(m[i][j] <= prev) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        v[i][j] = true;
        int path = 1;
        for(auto& x: dv){
            if(i+x[0] >= m.size() || i+x[0] < 0 || j+x[1] >= m[0].size() || j+x[1] < 0 || v[i+x[0]][j+x[1]]) continue;
            path = max(path,dfs(m,v,i+x[0],j+x[1], m[i][j],memo) + 1);
        }
        v[i][j] = false;
        return memo[i][j] = path;
    }
};