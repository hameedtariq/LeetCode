/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNo= de *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int prev = INT_MAX;
        bool hit = false;
        hit = inorder(root,prev,hit);
        root->left=root->right=nullptr;
        return hit;
    }
    bool inorder(TreeNode* root, int& prev, bool& hit){
        if(!root) return true;
        bool ans = inorder(root->left,prev,hit);
        if(hit) {
            if(!(prev < root->val)) return false;
        }
        else
            hit = true;
        prev = root->val;
        ans = ans && inorder(root->right, prev,hit);
        return ans;       
    }
};