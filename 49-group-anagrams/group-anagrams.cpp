class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::string> sorted;

        for (std::string s : strs) {
            std::sort(s.begin(), s.end());
            sorted.push_back(s);
        }

        std::unordered_map<std::string, std::vector<std::string>> map;

        for (int i = 0; i < strs.size(); i++)
            map[sorted[i]].push_back(strs[i]);

        std::vector<std::vector<std::string>> ans;

        for (const std::pair<std::string, std::vector<std::string>>& p : map)
            ans.push_back(p.second);

        return ans;
    }
};