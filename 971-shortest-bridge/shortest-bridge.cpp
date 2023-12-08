class Solution {
    vector<vector<int>> dv = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        cout << n*n << endl;
        int x = n,y = n;
        for(int i =0; i <n; i++) {
            for(int j=0; j<n;j++){
                if(grid[i][j] == 1){
                    x =i; y =j;
                    break;
                }
            }
            if(x == i) break;
        }
        cout << x << " , " << y << endl;
        queue<pair<int,int>> q;
        dfs(grid,q,x,y,n); // detect one of the islands island and record the surround water zeros of it.
        int levelSize = q.size();
        cout << levelSize << endl;
        int count = 0;
        while(!q.empty()){
            count++;
            cout << count << "," << levelSize << endl;
            for(int i =0; i<levelSize; i++) { // loops over one level
                auto w =  q.front(); q.pop();                
                for(auto& a: dv){
                    int newX = w.first + a[0];
                    int newY = w.second + a[1];
                    if(newX >=0 && newX <n && newY >=0 && newY < n ){
                        if(grid[newX][newY] == 1) {
                            cout << count << endl;
                            return count;
                        }
                        else if(grid[newX][newY] == 0){
                            grid[newX][newY] = '2';
                            q.push(make_pair(newX,newY));
                        }
                    }            
                }
            }
            levelSize = q.size();            
        }
        cout << count << endl;
        return count;
    }
    void dfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int& i, int& j, int& n){
        // if(i < 0 || i >= n || j<0 || j>=n ) return;
        grid[i][j] = 2; // mark visited
        for(auto& a: dv){
            int newX = i+a[0];
            int newY = j+a[1];
            if(newX >=0 && newX <n && newY >=0 && newY < n ){
                // cout << newX << "," << newY << endl;
                if(grid[newX][newY] == 1)
                    dfs(grid,q,newX,newY,n);
                else if(grid[newX][newY] == 0)
                    q.push(make_pair(newX,newY));
                // cout << "END" << endl;
            }            
        }
    };
};