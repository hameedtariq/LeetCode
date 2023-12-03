class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int start = 0;
        dfs(rooms, visited, start);
        
        for(int i =0; i<n; i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int& i){
        if(visited[i]) return;
        visited[i] = true;
        for(auto& a: rooms[i]){
            dfs(rooms,visited,a);
        }
    }
};