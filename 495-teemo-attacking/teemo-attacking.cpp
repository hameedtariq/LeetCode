class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
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