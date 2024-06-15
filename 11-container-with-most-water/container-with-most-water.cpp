bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right) {
            int y = min(height[left],height[right]);
            int x = right-left;
            maxVol = max(x*y,maxVol);

            if(height[left] <= height[right]) left++;
            else right--;

        }
        return maxVol;
    }
};