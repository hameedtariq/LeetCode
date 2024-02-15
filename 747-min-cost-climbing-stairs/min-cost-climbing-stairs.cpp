class Solution {
public:
    int memory[1001];
    vector<int>arr;

    int min_cost(int idx)
    {
          if(idx >= (int)arr.size())
          return 0;

          int &ret = memory[idx];
          if(ret!=-1)
          return ret;


          int one_step = arr[idx] + min_cost(idx+1);
          int two_steps = arr[idx] + min_cost(idx+2);

          return ret = min(one_step , two_steps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        arr = cost;
        memset(memory ,-1 , sizeof(memory));
        return min (min_cost(0) , min_cost(1));     
    }
};