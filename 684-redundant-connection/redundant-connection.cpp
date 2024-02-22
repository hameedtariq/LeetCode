class UnionFind
{
private:
  vector<int> parent;
  int count;

public:
  UnionFind(int s)
  {
    parent.resize(s);
    for (int i = 0; i < s; i++)
    {
      parent[i] = i;
    }
    count = s;
  }
  // finds the root parent of a node group and returns it.
  int find(int x)
  {
    if (x != parent[x])
    {
      x = find(parent[x]);
    }
    return x;
  }
  void unify(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
    {
      if (rootX > rootY)
      {
        parent[rootY] = rootX;
      }
      else
      {
        parent[rootX] = rootY;
      }
    }
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(1001);
        for(auto e: edges) {
            if(uf.find(e[0]) == uf.find(e[1])) {
                return e;
            }else {
                uf.unify(e[0],e[1]);
            }
        }
        return {};
    }
};