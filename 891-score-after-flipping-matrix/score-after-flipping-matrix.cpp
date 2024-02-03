class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int sum=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0)
                    grid[i][j]=1;
                    else{
                        grid[i][j]=0;
                    }

                }
            }
        }
        for(int i=0;i<n;i++){
            int count0=0;
            int count1=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==0) count0++;
                else count1++;
                
            }
            if(count1<count0){
                for(int j=0;j<m;j++){
                if(grid[j][i]==0) grid[j][i]=1;
                else grid[j][i]=0;
                }
                
            }

            }
        
        //into binary
        
        for(int i=0;i<m;i++){
            int pro=1;
            for(int j=n-1;j>=0;j--){
                sum+=(pro*grid[i][j]);
                pro*=2;
            }
        }
        return sum;
        
    }
};