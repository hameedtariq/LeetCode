bool _ = [](){cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); return true;};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> count(26, 0);
        for(auto &i: s) {
            count[i-'a']++;
        }
        vector<bool> inStack(26,false);
        for(int i = 0; i < s.size(); i++) {
            count[s[i]-'a']--;
            if(inStack[s[i]-'a']) continue;
            while(!st.empty() && st.top() > s[i] && count[st.top()-'a'] > 0){
                inStack[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            inStack[s[i]-'a'] = true;
        }
        string ans;
        while(!st.empty()) {
            ans+= st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};