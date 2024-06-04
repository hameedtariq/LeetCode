class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        stack<char> st;
        vector<bool> isInStack(26, false);

        for (auto i : s)
        {
            count[i]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]]--;

            if (isInStack[s[i] - 'a']) continue;

            while (!st.empty() && st.top() > s[i] && count[st.top()] > 0) 
            {
                isInStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            isInStack[s[i] - 'a'] = true;
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            cout << st.top() << " ";
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};