class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int i = d.size()-1;
        int carry = 1;
        while(i >= 0 && carry == 1) {
            int temp = (d[i] + carry) / 10;
            d[i] = (d[i] + carry) % 10;
            carry = temp;
            i--;
        }
        if(carry == 1) {
            d.insert(d.begin(),1);
        }
        return d;
    }
};