class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // do row flips
        for(int i = 0;i <rows; i++) {
            if(grid[i][0] == 0) {
                cout << "Flipped Row: " << i << endl; 
                flip(grid, i);
            }
        }
        // do column flips
        for(int i = 0;i <cols; i++) {
            int count = 0; // tracks ones in ith column 
            for(int j=0; j<rows; j++){
                if(grid[j][i] == 1) count++;
            }
            if(count < ceil((float)rows/2)) {
                cout << "Flipped Col: " << i << endl; 
                flip(grid, i, false);
            }
        }
        int ans = 0;
        for(int i = 0;i <rows; i++) {
            ans += binaryToDecimal(grid[i]);
        }
        return ans;
    }
    void flip(vector<vector<int>>& grid, int k, bool row = true) {
        if(row) {
            int rowSize = grid[0].size();
            for(int i =0; i<rowSize; i++) {
                grid[k][i] = !grid[k][i];
            }
        }else {
            int colSize = grid.size();
            for(int i =0; i<colSize; i++) {
                grid[i][k] = !grid[i][k];
            }
        }
    }
    int binaryToDecimal(const vector<int>& binaryVector) {
        int decimal = 0;
        int power = 1;

        // Iterate through the binary digits in reverse order
        for (int i = binaryVector.size() - 1; i >= 0; --i) {
            decimal += binaryVector[i] * power;
            power *= 2;
        }

        return decimal;
    }
};