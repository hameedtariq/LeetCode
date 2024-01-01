bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    struct myComp {
        constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b) const noexcept {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans(k,-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;
        for(int i =0; i< n;) {
            int j =i+1;
            for(; j<n && nums[j] == nums[j-1]; j++){};
            pq.push({nums[i], j-i});
            i=j;
        }
        for(int i=0; i<k;i++){
            ans[i] = pq.top().first;pq.pop();
        }
        return ans;
    }
};