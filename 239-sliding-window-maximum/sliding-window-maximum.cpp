class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> q;

        
        for(int i =0, l=0; i<n; i++) {
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // front value has expired since window has moved
            if(l > q.front()) {
                q.pop_front();
            }

            if(i+1 >= k) {
                l++;
                ans.push_back(nums[q.front()]);
            }

        }
        return ans;


        for(int j = 0; j< n-k+1; j++) {
            int m = INT_MIN;
            for(int i = 0; i<k; i++) {
                m = max(nums[j+i], m);
            }
            ans.push_back(m);
        }
        return ans;
    }
};