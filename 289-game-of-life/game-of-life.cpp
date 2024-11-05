class Solution {
    vector<vector<int>> dv = {{0,1}, {0, -1}, {1,0}, {-1,0}, {1,1}, {1, -1}, {-1,1}, {-1,-1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copyBoard(board.begin(), board.end());
        int X = board.size();
        int Y = board[0].size();
        for(int i=0; i<X; i++) {
            for(int j=0; j<Y; j++) {
                int alive = 0;
                for(auto &v: dv) {
                    int x = i + v[0];
                    int y = j + v[1];
                    if(x >= 0 && x < X && y >= 0 && y < Y) {
                        alive += copyBoard[x][y];
                    }
                }
                if(copyBoard[i][j] == 1) {
                    if(alive < 2) {
                        board[i][j] = 0;
                    }else if (alive <=3 ) {
                        board[i][j] = 1;
                    }else {
                        board[i][j] = 0;
                    }
                }else {
                    if(alive == 3) {
                        board[i][j] = 1;
                    }
                }
                
            }
        }
    }
};