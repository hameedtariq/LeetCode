class Solution {
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vvi res;
        dfs(nums, res, 0);
        return res;
    }
    void dfs(vi& nums, vvi &res, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        };
        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            dfs(nums, res, i+1);
            swap(nums[i], nums[j]);
        }
    }
};