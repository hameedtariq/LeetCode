bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        // unordered_map<int, int> m;
        stack<int> s;
        for(int i =0; i<2*n; i++) {
            while(!s.empty() && nums[s.top()] < nums[i%n]) {
                ans[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }

        
        return ans;
    }
};