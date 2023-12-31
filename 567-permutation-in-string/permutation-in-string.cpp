bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int x = s1.length();
        int y = s2.length();
        
        unordered_map<char, int> m;
        for(auto&l: s1){
            m[l]++;
        }
        int p = 0, q = 0;
        while(q<y){    
            // window size is less that s1 size 
            // and s2[q] was present in s1 
            // and there is a occurance available        
            while(q-p < x && m.find(s2[q]) != m.end() && m[s2[q]] > 0){
                m[s2[q]]--;
                q++;
            }
            // if subsequence that matched has same length as x then we found a match
            if(q-p == x) return true;
            // determine reason of loop break
            // 1- does not exist
            if(m.find(s2[q])==m.end()){
                while(p!=q){
                    m[s2[p]]++;
                    p++;
                }
                p = q = q+1;
            }else { // 2- exists but occupied
                if(p!=q){
                    m[s2[p]]++;
                }
                p++;
                q;
            }
            // else we need to move the window
            
        }
        return false;
        
    }
};