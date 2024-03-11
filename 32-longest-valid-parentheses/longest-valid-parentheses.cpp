class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sk;
        sk.push(-1);
        int maxLen = 0;
        for(int i =0; i<s.size(); i++) {
            int st = sk.top();
            if(st != -1 && s[i] == ')' && s[st] == '(') {
                sk.pop();
                maxLen = max(maxLen, i - sk.top());
            }else sk.push(i);
        }
        return maxLen;
    }
};