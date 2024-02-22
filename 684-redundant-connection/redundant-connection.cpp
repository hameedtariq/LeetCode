class Solution {
public:
    vector<int> par;
    vector<int> treeSize;

    int find_parent(int i){
        if(par[i] == i){
            return i;
        }
        return par[i] = find_parent(par[i]);
    }

    void merge(int u, int v){
        if(treeSize[u] > treeSize[v]){
            swap(u, v);
        }
        par[u] = v;
        treeSize[v] += treeSize[u];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        treeSize.assign(n+1, 1);
        for(int i=1; i<=n; i++){
            par[i] = i;
        }

        vector<int> ans;
        for(vector<int> &edge: edges){
            int p1 = find_parent(edge[0]);
            int p2 = find_parent(edge[1]);
            if(p1 != p2){
                merge(p1, p2);
            }
            else{
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }
        }
        return ans;
    }
};