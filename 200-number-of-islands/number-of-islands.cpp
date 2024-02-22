class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        count = size;

        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            count--;  // Decrement count when union is performed
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() const {
        return count;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;  // Number of connected components
};


class Solution {
private:
    int rows;
    int cols;
    const vector<vector<int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        UnionFind uf(rows*cols);        
        int countOnes = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    countOnes++;

                    // Convert 2D coordinates to 1D index
                    int currentIndex = i * cols + j;

                    // Check and union with adjacent '1's
                    if (i > 0 && grid[i - 1][j] == '1') {
                        uf.unite(currentIndex, currentIndex - cols);
                    }
                    if (i < rows - 1 && grid[i + 1][j] == '1') {
                        uf.unite(currentIndex, currentIndex + cols);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        uf.unite(currentIndex, currentIndex - 1);
                    }
                    if (j < cols - 1 && grid[i][j + 1] == '1') {
                        uf.unite(currentIndex, currentIndex + 1);
                    }
                }
            }
        }

        // The number of islands is the total number of '1's minus the number of unions
        return countOnes - (rows*cols - uf.getCount());
    }
    
};