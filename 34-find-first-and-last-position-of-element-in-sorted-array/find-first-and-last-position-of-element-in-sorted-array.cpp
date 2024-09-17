class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        bs(nums, target, ans, 0, nums.size() - 1);
        return ans;
    }

private:
    void bs(vector<int>& nums, int target, vector<int>& ans, int l, int r) {
        if (l > r) return;
        int mid = l + (r - l) / 2;

        if (nums[mid] == target) {
            // Update ans[0] and ans[1] if needed
            if (ans[0] == -1 || mid < ans[0]) ans[0] = mid;
            if (ans[1] == -1 || mid > ans[1]) ans[1] = mid;
            // Search both left and right halves
            bs(nums, target, ans, l, mid - 1);
            bs(nums, target, ans, mid + 1, r);
        } else if (nums[mid] < target) {
            bs(nums, target, ans, mid + 1, r);
        } else {
            bs(nums, target, ans, l, mid - 1);
        }
    }
};
