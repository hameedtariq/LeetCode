class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // sort(worker.begin(),worker.end(), [](int& a, int& b) {
        //     return a < b;
        // });
        int n = profit.size();
        vector<pair<int,int>> jobs(n);
        for(int i =0; i<n; i++){
            jobs[i].first = (profit[i]);
            jobs[i].second = (difficulty[i]);
        }
        sort(jobs.begin(),jobs.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        }); // sort by profit;
        int total = 0;
        for(auto& w: worker) {
            auto it = find_if(jobs.begin(), jobs.end(), [w](auto& job) {
                return (job.second <= w);
            });
            if(it != jobs.end()){
                total += (*it).first;
            }
        }
        return total;
    }
};