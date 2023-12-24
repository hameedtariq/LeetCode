class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        int start = 0, end = 0;
        bool odd = n%2 != 0;
        for(int i =0; i<n; i++){
            int left = i,right = i;          
            while(left >=0 && right < n && s[left] == s[right]){
                left--;right++;
            }
            if(len < right-left+1){
                len = right-left+1;
                start = left+1;
                end = right-1;
            }
            left = i; right = i+1;
            while(left >=0 && right < n && s[left] == s[right]){
                left--;right++;
            }            
            if(len < right-left+1){
                len = right-left+1;
                start = left+1;
                end = right-1;
            }
        }
        string res = s.substr(start,end-start+1);
        return res;
    }
};