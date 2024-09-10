class Solution {
public:
    string reverseOnlyLetters(string s) {
        if(s.size() == 0) return s;
        int start = 0;
        int end = s.size()-1;
        while(start < end) {
            if(!isalpha(s[start])){
                start++;
            }else if (!isalpha(s[end]))  {
                end--;
            }else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};