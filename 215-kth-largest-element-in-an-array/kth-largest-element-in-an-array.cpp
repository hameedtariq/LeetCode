class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        std::priority_queue<int> h;
        for (auto num: nums) {
            h.push(num);
        }
        for (int i=0; i<k-1; i++)
            h.pop();
        return h.top();



        
    }
};