class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<int> v(26);
        for(auto&str: strs) {
            fill(v.begin(), v.end(), 0);
            for(auto& c: str) {
                v[c-'a']++;
            }
            string key = to_string(v[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(v[i]);
            }
            m[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& pair: m) {
            res.push_back(pair.second);
        }
        return res;
    }
};
