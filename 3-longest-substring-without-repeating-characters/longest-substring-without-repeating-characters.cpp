class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        unordered_set<char> set;
        int left = 0, right = 1;
        set.insert(s[left]);
        int size = 1;
        while(right < s.size()) {
            if(set.find(s[right]) != set.end()) { 
                while(left < right && set.find(s[right]) != set.end()) {
                    set.erase(s[left]);
                    left++;
                }
               
            }
            set.insert(s[right]);
            right++;
            size = max(size, right-left);
        }
        return size;
    }
};