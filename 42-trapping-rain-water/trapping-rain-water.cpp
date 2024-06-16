class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int left_max = height[left];
        int right = height.size() - 1;
        int right_max = height[right];
        int vol = 0;
        while(left < right) {
            if(left_max < right_max) {
                left++;
                left_max = max(left_max, height[left]);
                vol += left_max - height[left];
            }else {
                right--;
                right_max = max(right_max, height[right]);
                vol += right_max - height[right];
            }
        }
        return vol;
    }
};