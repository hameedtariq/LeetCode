class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) return ans;

        for(int i = 1; i<numRows; i++) {
            ans.push_back({});
            for(int j = 0; j < i+1; j++) {
                int val = 0;
                if(j-1 >= 0) {
                    val+= ans[i-1][j-1];
                }
                if(j < ans[i-1].size()) {
                    val+= ans[i-1][j];
                }
                ans[i].push_back(val);
            }
        }
        return ans;
    }
};