class Solution {
public:
    bool isval(int i, int j, int n){
        return (i>=0 && j>=0 && j<n && i<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int cdist = q.front().first;
            int i=q.front().second.first,j=q.front().second.second;
            q.pop();
            for(int ii=-1;ii<=1;ii++){
                for(int jj=-1;jj<=1;jj++){
                    if(!(ii==0 && jj==0) && isval(i+ii,j+jj,n) && grid[ii+i][j+jj] == 0){
                        if(dist[i+ii][j+jj]>cdist+1){
                            dist[i+ii][j+jj] = cdist+1;
                            q.push({cdist+1,{i+ii,j+jj}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];        
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();