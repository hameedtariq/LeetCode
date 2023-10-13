/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool zigZag = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> a(levelSize);
            for(int i =0; i<levelSize; i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                int index = zigZag ? i : levelSize - 1 -i;
                a[index] = (q.front()->val);
                q.pop();
            }            
           
            ans.push_back(a);
            zigZag = !zigZag;
        }
        root->left = nullptr;
        root->right = nullptr;
        return ans;
    }
};