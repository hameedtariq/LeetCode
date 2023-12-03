class Solution{
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            queue<pair<int,int>> BFS {{{entrance[0], entrance[1]}}};
            pair<int, int> CurrentCell;
            int MaxX = size(maze) - 1;
            int MaxY = size(maze[0]) - 1;
            int X;
            int Y;
            int steps = 0;
            char Cell = '.';
            char Wall = '+';
            int size;
            int Directions [] {0, 1, 0, -1, 0};
            while(!BFS.empty()){
                ++steps;
                size = BFS.size();
                for(int i=0; i<size; i++){
                    CurrentCell = BFS.front();
                    BFS.pop();
                    for(int j=0; j<4; j++){
                        X = CurrentCell.first + Directions[j];
                        Y = CurrentCell.second + Directions[j + 1];
                        if(X <= MaxX && X >= 0 && Y <= MaxY && Y >= 0 &&
                            maze[X][Y] == Cell){
                            if((X == MaxX || X == 0 || Y == MaxY || Y == 0) &&
                                (X != entrance[0] || Y != entrance[1]))
                                return steps;
                            maze[X][Y] = Wall;
                            BFS.push({X, Y});
                        }
                    }
                }
            }
            return -1;
        }
};