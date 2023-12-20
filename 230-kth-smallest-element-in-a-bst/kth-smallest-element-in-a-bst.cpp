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
bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        LVR(root,ans,k);
        root->left=root->right=nullptr;
        return ans;
    }
    void LVR(TreeNode* root, int& ans, int& k){
        if(!root) return;
        LVR(root->left, ans, k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        LVR(root->right,ans,k);
    }
};