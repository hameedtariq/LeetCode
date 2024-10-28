class Solution {
public:
    int titleToNumber(string columnTitle) {
        // A -> 65

        int ans = 0;
        int size = columnTitle.size();

        for(int i = 0, j = size-1; i< size; i++,j--) {
            int mul = pow(26, j);
            int x = columnTitle[i] -'A' + 1; // since A is 1
            ans += x*mul;
        }
        return ans;
    }
};