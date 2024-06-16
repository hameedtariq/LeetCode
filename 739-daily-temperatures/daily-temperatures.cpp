class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        for(int i =t.size()-1; i >= 0; i--) {
            int last = i + 1;
            while(last < t.size() && t[i] >= t[last]) {
                if(ans[last] == 0) {
                    last = t.size();
                    break;
                }
                last += ans[last];
            }
            if(last == t.size()) ans[i] = 0;
            else ans[i] = last-i;
        }
        return ans;
    }
};