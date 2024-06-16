class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0) return 0;

        int left = 0;
        int right = size - 1;
        int left_max = 0;
        int right_max = 0;
        int totalVol = 0;

        while (left <= right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    totalVol += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    totalVol += right_max - height[right];
                }
                right--;
            }
        }

        return totalVol;
    }
};
