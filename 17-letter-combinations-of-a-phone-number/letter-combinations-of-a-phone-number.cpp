class Solution {
public:
    vector<string> letterCombinations(string d) {
        if(d.size() == 0) {
            return vector<string>();
        }
        unordered_map<char,vector<char>> m {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'v','t','u'}},
            {'9', {'y','w','x', 'z'}},
        };
        string temp = "";
        vector<string> ans;
        dfs(d,temp, ans,m,0);
        return ans;
    }

    void dfs(string &d, string &temp, vector<string> &ans, unordered_map<char,vector<char>> &m, int i) {
        if(d.size() == i) {
            ans.push_back(temp);
            return;
        };
        for(auto& x: m[d[i]]) {
            temp.push_back(x);
            dfs(d,temp,ans,m,i+1);
            temp.pop_back();
        }
    }
};