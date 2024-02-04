class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> s;
        int count = 0;
        for(auto& c: str) {
            if(c == '(') s.push(c);
            else {
                if(!s.empty()) {
                    s.pop();
                }else {
                    count++;
                }
            }
        }
        count += s.size();
        return count;
    }
};