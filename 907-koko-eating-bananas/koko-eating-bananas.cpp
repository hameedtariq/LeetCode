class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isSolution(piles, h, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool isSolution(vector<int>& piles, int h, int k) {
        for (int size : piles) {
            h -= ceil((double)size / k);
            if (h < 0) return false; // Too slow
        }
        return true; // Can finish in h hours
    }
};
