class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>result;
       int n=nums.size();
       if(n==1){
        result.push_back(nums);
        return result;
       }
       sort(nums.begin(),nums.end());
      do{
        result.push_back(nums);
      }
      while(next_permutation(nums.begin(),nums.end()));
      return result;
    }

};