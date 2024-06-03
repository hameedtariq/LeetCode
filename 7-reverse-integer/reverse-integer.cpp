class Solution {
public:
    int reverse(int x) {
        string xx = to_string(x);
        std::reverse(xx.begin(), xx.end());
        try {
            if(x < 0)
                return -1 * stoi(xx);
            else 
                return stoi(xx);
        }catch(std::out_of_range e) {
            return 0;
        }
        
    }
};