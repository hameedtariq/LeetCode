class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // at each node, for each outgoing edge, perform dfs to see if it returns true i.e it hits a terminal node and perform AND operation to see if it all hit terminal
        int n = graph.size();
        vector<char> history(n, '0');
        vector<int> ans;
        for(int i =0; i<n; i++){
            if(dfs(graph, history, i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& graph,vector<char>& history, int& i){
        if(history[i] == '2' || graph[i].size() == 0) {
            history[i] = '2';
            return true;
        }
        if(history[i] == '1') return false;
        history[i] = '1';

        bool x = true;
        for(int j =0; j< graph[i].size(); j++){
            x = x && dfs(graph, history, graph[i][j]);
        }
        if(x){
            history[i] = '2';
            return true;
        }
        return false;
    }
};