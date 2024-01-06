bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==trust.size()) return -1;
        unordered_map<int,vector<int>> graph;
        unordered_map<int,vector<int>> graph2;
        
        for(int i =0; i< trust.size(); i++){
            graph[trust[i][0]].push_back(trust[i][1]);
            graph2[trust[i][1]].push_back(trust[i][0]);
        }
        for(int i =1; i<= n; i++){
            if(graph[i].size() == 0){
                if(graph2[i].size() == n-1) return i;
            }
        }
        
        return -1;
    }
};