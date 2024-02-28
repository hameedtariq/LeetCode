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
    typedef vector<int>::iterator vi;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, vi preStart, vi preEnd, vi inStart, vi inEnd) {
        // base cases
        if(preStart == preEnd || inStart == inEnd) return nullptr;
        TreeNode* root = new TreeNode(*preStart);
        auto rootInorder = inStart;
        for(; rootInorder != inEnd; rootInorder++) {
            if(*rootInorder == *preStart) break;
        }
        int sizeLeft = rootInorder - inStart;
        root->left = build(preorder, inorder, preStart+1, preStart + sizeLeft + 1, inStart, inStart+sizeLeft+1);
        root->right = build(preorder, inorder, preStart+sizeLeft+1, preEnd, inStart+sizeLeft+1, inEnd);
        return root;
    }
};