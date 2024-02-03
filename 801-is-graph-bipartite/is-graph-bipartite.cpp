class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int size = graph.size();
        vector<short> visited(size,-1); // mark all nodes as unvisited
        
        // run for every node
        for(int k=0; k< size; k++){
            // start from node kth node
            if(visited[k] != -1) continue;
            q.push(k);
            int levelSize = 1;
            int color = 0;
            while(!q.empty()) {
                for(int i =0; i< levelSize; i++){
                    int node = q.front(); q.pop();
                    visited[node] = color;
                    for(auto& n: graph[node]){
                        if(visited[n] == -1) // not visited
                            q.push(n);
                        else if(color == visited[n]) // conflict in color of already visited node
                            return false;
                    }
                }
                color = color == 0 ? 1 : 0; // change color;
                levelSize = q.size(); // recalculate level size
            }
        }
        
        return true; // all nodes were visited
    }
};