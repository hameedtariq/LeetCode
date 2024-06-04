class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans;
        for(int i =0; i< num.size(); i++) {
            while(!st.empty() && num[i] < st.top() && k) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k && !st.empty()) {
            st.pop();
            k--;
        }
        if(st.size() == 0) return "0";

        while(!st.empty()) {
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        for(int i =0; i<ans.size(); i++) {
            if(ans[i] == '0') {
                if( i == ans.size()-1) return "0";
                else continue;
            }
            else{ 
                ans.erase(ans.begin(), ans.begin()+i);
                break;
            }
            
        }
        
        return ans;
    }
};