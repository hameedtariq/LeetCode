class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c1(1001,0);
        vector<int> c2(1001,0);
        vector<int> ans;
        for(auto &n : nums1) {
            c1[n]++;
        }
        for(auto &n : nums2) {
            c2[n]++;
        }
        for(int i = 0; i<1001; i++){
            int com = min(c1[i], c2[i]);
            for(int j = 0; j<com; j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};