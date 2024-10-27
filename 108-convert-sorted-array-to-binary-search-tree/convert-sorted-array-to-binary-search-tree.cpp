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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size()-1);
    }
    TreeNode* BST(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;

        int mid = (left + right)/2;

        TreeNode* p = new TreeNode(nums[mid]);

        p->left = BST(nums, left, mid - 1);
        p->right = BST(nums, mid+1, right);

        return p;
    }
};