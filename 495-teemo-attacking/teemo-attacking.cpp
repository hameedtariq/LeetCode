class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total = duration;
        for(int i = 1; i<n; i++){
            if(timeSeries[i] - timeSeries[i-1] < duration){
                total += timeSeries[i] - timeSeries[i-1];
            }else {
                total += duration;
            }
        }
        return total;
    }
};