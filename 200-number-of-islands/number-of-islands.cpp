class Solution {
public:
    const vector<pair<int,int>> dv = {make_pair(0,1),make_pair(1,0),make_pair(-1,0), make_pair(0,-1)};
    int numIslands(vector<vector<char>>& map) {
        int count = 0;
        vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
        for(int i =0; i< map.size(); i++){
            for(int j =0; j< map[0].size(); j++){ // atleast n^2 to visit all nodes.
                if(visited[i][j] || map[i][j] == '0') continue;
                dfs(map,visited,i,j); // in worst case all are ones so, it will n^2 but if this is n^2 then it wont be called again.
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& map, vector<vector<bool>>& visited, int i, int j){
        if(map[i][j] == '0') return;
        visited[i][j] = true;
        for(auto& v: dv) {
            // bound checking
            if(i+v.first < 0 || i+v.first >= map.size()) continue;
            if(j+v.second < 0 || j+v.second >= map[0].size()) continue;

            if(!visited[i+v.first][j+v.second]){
                dfs(map,visited,i+v.first,j+v.second);
            }
        }
    }
};