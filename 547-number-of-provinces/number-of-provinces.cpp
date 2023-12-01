class Solution {
public:// connected components basically
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int prov = 0;
        vector<bool> visited(n, false);
        for(int i =0; i<n; i++){
            if(!visited[i]){
                prov++;
                dfs(isConnected, visited, i, n);
            }
        }
        return prov;
    }
    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int& i, int& n){
        visited[i] = true;
        for(int j = 0; j<n;j++){
            if(isConnected[i][j] && !visited[j]){
                dfs(isConnected, visited, j, n);
            }
        }

    }
};