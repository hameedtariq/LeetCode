class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(),-1);
        unordered_set<string> w(wordDict.begin(),wordDict.end());
        return recursive(s,w,0,s.size(),memo);
    }
    bool recursive(string& s, unordered_set<string>& wordDict, int x, int n,vector<int>&memo){
        if(x >= n) return true;
        if(memo[x] != -1) return memo[x];
        string ans = "";
        bool ret = false;
        for(int i=x; i<n; i++){
            ans+= s[i];
            if(wordDict.find(ans) != wordDict.end()) {// found match
                ret = ret || recursive(s,wordDict,i+1,n,memo);
            }
        }
        memo[x] = ret;
        return ret;
    }
};