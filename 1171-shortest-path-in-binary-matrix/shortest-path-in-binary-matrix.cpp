struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Solution {
    const vector<Point> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int numRows;
    int numCols;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;

        queue<Point> q;
        int count = 0;
        numRows = grid.size();
        numCols = grid[0].size();
        const int goalX = numRows - 1;
        const int goalY = numCols - 1;

        q.push(Point(0, 0));
        grid[0][0] = 2; // mark visited

        while (!q.empty()) {
            count++;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto next = q.front();
                q.pop();

                if (next.x == goalX && next.y == goalY) return count;

                for (const auto& dir : directions) {
                    int newX = dir.x + next.x;
                    int newY = dir.y + next.y;

                    if (isValid(newX, newY) && grid[newX][newY] == 0) {
                        if (newX == goalX && newY == goalY) return count + 1;
                        q.push(Point(newX, newY));
                        grid[newX][newY] = 2; // mark visited
                    }
                }
            }
        }

        return -1;
    }

private:
    bool isValid(int x, int y) {
        return x >= 0 && x < numRows && y >= 0 && y < numCols;
    }
};
