class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        int a = cost[cost.size()-1];
        int b = 0;
        for(int i = cost.size() - 2; i >=0; i--){
            int t = a;
            a = cost[i] + min(a, b);
            b = t;
        }
        return min(a,b);
    }
};