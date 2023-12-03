class Solution {
    vector<vector<int>> dv = {
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q;
        maze[entrance[0]][entrance[1]] = 'x';
        q.push({entrance[0], entrance[1], 0});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto& e: dv){
                int newX = x[0] + e[0];
                int newY = x[1] + e[1];
                if((newX < 0 || newX >= m || newY < 0 || newY >= n)){
                    if((x[2] != 0))
                        return x[2];
                    else continue;
                }
                if(maze[newX][newY] == '.'){
                    maze[newX][newY] = 'x';
                    q.push({newX, newY, x[2] + 1});
                }
            }
        }
        return -1;
    }
};