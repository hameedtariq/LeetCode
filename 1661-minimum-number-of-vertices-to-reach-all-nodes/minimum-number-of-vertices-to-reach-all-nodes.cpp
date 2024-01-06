class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // 1- count all nodes that don't have incoming edge
        vector<int> g(n,0);
        for(auto &e: edges){
            g[e[1]]++; // count of incoming edges;
        }
        vector<int> ans;
        for(int i =0; i<n; i++){
            if(g[i] == 0) ans.push_back(i); 
        }
        return ans;
    }
};