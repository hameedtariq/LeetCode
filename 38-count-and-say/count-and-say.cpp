class Solution {
public:
    string solve(int n)
    {
        if(n==1)return "1";
        string ashu = solve(n-1);
        string raj = "";
        int i = 0 ;
        int j = 0 ;
        int m = ashu.size();
        while(i < m and j < m)
        {
            char c = ashu[i];
            while(i<m and ashu[i] == c)
            {
                i++;
            }
            int cnt = i-j;
            raj.push_back('0' + cnt);
            raj.push_back(c);
            // i++;
            j=i;
        }
        cout<<raj<<" ";
        return raj;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};