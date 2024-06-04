class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto &n: nums){
            s.push_back(to_string(n));
        }
        sort(s.begin(),s.end(), [](auto& a, auto& b){
            return a+b > b+a;
        });
        if(s[0][0] == '0') {
            return "0";
        }
        string ans;
        for(auto &n: s){
            ans += n; 
        }
        return ans;
    }
};