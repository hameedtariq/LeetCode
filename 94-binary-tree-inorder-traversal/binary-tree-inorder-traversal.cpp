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
    typedef TreeNode* t;
    typedef vector<int> vi;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vi ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(t r, vi& ans) {
        if(!r) return;
        inorder(r->left,ans);
        ans.push_back(r->val);
        inorder(r->right,ans);
    }
};