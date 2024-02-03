class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>&color,int col) {
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1){
                color[it]=!col;
                if(!dfs(it,graph,color,!col)){return false;}
            }
            else{
                if(color[it]==col){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,graph,color,0)){return false;}
            }
        }
        return true;

    }
};