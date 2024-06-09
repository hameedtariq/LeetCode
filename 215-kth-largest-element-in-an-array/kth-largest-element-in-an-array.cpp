class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto& a: nums) {
            if(q.size() < k) {
                q.push(a);
            }else {
                if(q.top() < a) {
                    q.pop();
                    q.push(a);
                }
            }
        }
        return q.top();
    }
};