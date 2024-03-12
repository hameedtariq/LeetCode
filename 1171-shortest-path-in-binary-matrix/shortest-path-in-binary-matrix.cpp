class Solution {
    vector<vector<int>> dv = {{0,1}, {0, -1}, {1,0}, {-1,0}, {1,1}, {-1, -1}, {1,-1}, {-1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // base edge case
        if(grid[0][0] != 0) return -1;
        queue<vector<int>> q;
        int count = 0;
        int goalX = grid.size()-1, goalY = grid[0].size()-1;
        q.push({0,0});
        grid[0][0] = 2; // mark visited
        int levelSize = 1;
        while(!q.empty()) {
            count++;
            for(int i =0; i<levelSize;i++) {
                auto next = q.front(); q.pop();
                
                if(next[0] == goalX && next[1] == goalY) return count;
                for(auto& v: dv) {
                    int newX = v[0] + next[0];
                    int newY = v[1] + next[1];
                    if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0) {
                        q.push({newX,newY});
                        grid[newX][newY] = 2; // mark visited
                    }
                }
            }
            levelSize = q.size();            
        }
        return -1;
    }
};