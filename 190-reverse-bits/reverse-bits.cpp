class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for(int i = 0; i< 32; i++) {
            rev <<= 1; // reverse 1 place to get room
            rev |= (n&1); // get last bit and add it to number
            n >>= 1; // right shift n to get next bit 
        }
        return rev;
    }
};