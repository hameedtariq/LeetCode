class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // check for each position, how many do i have to paint to get k
        // return the minimum.
        int n = blocks.size();
        int mn = n;
        for(int i =0;i<n; i++) {
            int x = 0;
            for(int j =i; j<n;j++) {
                if(blocks[j]== 'W') {
                    x++;
                }
                if(j-i+1 == k){
                    mn = min(x,mn);
                    break;
                }
            }
        }
        return mn;
    }
};