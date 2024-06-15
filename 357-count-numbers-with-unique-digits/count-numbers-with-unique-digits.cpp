class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1;
        // no leading zero
        for(int i =0; i<n;i++) {
            if(i == 0) count *= 9;
            else count *= (10-i);
        }
        // with leading zeros;
        for(int i = 1; i <= n; i++) {
            int c = 1;
            for(int j = 0; j < n-i; j++) {
                if(j==0) c *= 9;
                else c *= 10-j;
            }

            count+=c;
        }

        return count;
    }
};

// 10 * 9 * 8

// 0 