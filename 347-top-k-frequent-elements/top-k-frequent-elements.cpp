class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count;
        for(auto&a: nums) {
            count[a]++;
        }
        vector<pair<int,int>> ss;
        for(auto& x: count){
            ss.push_back(x);
        }
        sort(ss.begin(),ss.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });
        vector<int> ans(k);
        for(int i =0; i<k; i++){
            ans[i] = ss[i].first;
        }
        return ans;
    }
};