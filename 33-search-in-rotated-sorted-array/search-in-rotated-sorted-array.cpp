class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        int pi = -1;
        
        // Find the pivot
        while (l <= r) {
            int mid = (l + r) / 2;
            
            // Check if mid is pivot
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pi = mid;
                break;
            } 
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                pi = mid + 1;
                break;
            }

            // Decide which side to go
            if (nums[mid] >= nums[l]) {
                // Go right
                l = mid + 1;
            } else {
                // Go left
                r = mid - 1;
            }
        }
        
        // If pivot is not found, the array is not rotated, apply binary search on the whole array
        if (pi == -1) {
            return bs(nums, target, 0, n - 1);
        }
        
        // Search in the left half
        if (target >= nums[0] && target <= nums[pi - 1]) {
            return bs(nums, target, 0, pi - 1);
        }
        
        // Search in the right half
        return bs(nums, target, pi, n - 1);
    }

private:
    int bs(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
