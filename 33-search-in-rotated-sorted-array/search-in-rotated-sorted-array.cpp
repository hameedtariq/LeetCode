class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Determine which half is sorted
            if (nums[l] <= nums[mid]) {
                // Left half is sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1; // Target is in the sorted left half
                } else {
                    l = mid + 1; // Target is in the right half
                }
            } else {
                // Right half is sorted
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1; // Target is in the sorted right half
                } else {
                    r = mid - 1; // Target is in the left half
                }
            }
        }
        
        // Target not found
        return -1;
    }
};
