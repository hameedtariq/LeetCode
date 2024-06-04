class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;
        stack<int> s;
        for(int i =0; i<nums2.size(); i++) {
            while(!s.empty() && s.top() < nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for(auto &n: nums1) {
            if(m.find(n) != m.end())
                ans.push_back(m[n]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};