class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(n, res, 0, 0, s);
        return res;
    }
    void dfs(int& n, vector<string>& res, int opened, int closed, string& s) {
        if(opened == n && closed == n) {
            res.push_back(s);
        };
        if(opened < n) {
            s.append(1,'(');
            dfs(n, res, opened+1, closed, s);
            s.erase(s.size()-1);
        }
        if(closed < opened) {
            s.append(1,')');
            dfs(n, res, opened, closed+1, s);
            s.erase(s.size()-1);
        }
    }
};