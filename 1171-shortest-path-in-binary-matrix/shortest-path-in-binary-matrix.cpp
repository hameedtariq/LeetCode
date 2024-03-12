class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col));
        queue<pair<int,int>> queue;
        queue.push({0,0});
        visit[0][0] = 1;
         if (grid[0][0] != 0) {
            return -1;
        }
        int length = 1;
        while (!queue.empty()) {
            int queueLength = queue.size();
            for (int i = 0; i < queueLength; ++i) {
                pair<int,int> currPair = queue.front();
                queue.pop();
                int r = currPair.first;
                int c = currPair.second;
                if (r == row - 1 && c == col - 1) {
                    return length;
                }

                int neighbors[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
                for (int j = 0; j < 8; ++j) {
                    int newR = r + neighbors[j][0];
                    int newC = c + neighbors[j][1];
                    if (newR < 0 || newC < 0 || newR >= row || newC >= col || grid[newR][newC] || visit[newR][newC]) {
                        continue;
                    }
                    queue.push({newR, newC});
                    visit[newR][newC] = 1;
                }
            }
            length++;
        }
        return -1;
    }
};