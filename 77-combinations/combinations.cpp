class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
      auto t = rec(n, k, i);
      // for(auto& x: t) {
      //     x.insert(x.begin(),i);
      // }
      res.insert(res.end(), t.begin(), t.end());
    }
    return res;
  }
  vector<vector<int>> rec(int &n, int k, int i)
  {
    // base case
    // n-i > k
    if (i > n || k <= 0 || n - i < k - 1)
      return vector<vector<int>>();
    vector<vector<int>> res;
    for (int a = i + 1; a <= n; a++)
    {
      auto t = rec(n, k - 1, a);
      for (auto &x : t)
      {
        x.insert(x.begin(), i);
      }
      if (t.size() != 0)
        res.insert(res.end(), t.begin(), t.end());
    }
    if (res.size() == 0)
    {
      res.push_back(vector<int>(1, i));
    }
    return res;
  }
};