class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int cookies = s.size();
        for(int i =0 ;i<cookies; i++){
            if(count == g.size()) break;
            if(s[i] >= g[count])
                count++;
        }
        return count;
    }
};