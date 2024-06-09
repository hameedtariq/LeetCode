class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // std::priority_queue<int> h;
        // for (auto num: nums) {
        //     h.push(num);
        // }
        // for (int i=0; i<k-1; i++)
        //     h.pop();
        // return h.top();

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        auto f = nums.begin();
        auto l = nums.end();

        k = nums.size() - k;

        nth_element(f, f + k, l);

        return *(f + k);
    }
};