class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        for(int i = n; i>=2; i--){
            auto temp = second;
            second = second + first;
            first = temp;
        }
        return second;
    }
};