class Solution {
public:
    int solve(string &s,int i,int j,string &t,vector<vector<int>>&dp)
{
    if(j==t.size()-1)return 1;
    if(i>=s.size())return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    
    int ans=0;
    if(s[i]==t[j])
    {
        for(int z=i+1;z<s.size();z++)
        {
            if(t[j+1]==s[z]&&s.size()-z>=t.size()-j-1)
            {
                ans+=solve(s,z,j+1,t,dp);
            }
            
        }
    }
    return dp[i][j]=ans;
}

int numDistinct(string s, string t) {
    
    int ans=0;
    vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));

    for(int z=0;z<s.size();z++)
    {
        if(s[z]==t[0]&&s.size()-z>=t.size())
            ans+=solve(s,z,0,t,dp);
    }
    return ans;
}
};  