class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
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