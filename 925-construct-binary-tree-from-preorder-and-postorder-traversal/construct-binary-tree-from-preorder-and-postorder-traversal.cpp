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
    TreeNode* constructFromPrePost(vector<int>& a, vector<int>& b) {
        return rec(a.begin(),a.end(),b.begin(),b.end());
    }
    TreeNode* rec(vi preStart, vi preEnd, vi postStart, vi postEnd) {
        if(preStart >= preEnd || postStart >= postEnd) return nullptr;

        TreeNode* root = new TreeNode(*preStart);
        if (preStart + 1 == preEnd)
            return root;
        auto postOrderLeft = postStart; 
        for(;postOrderLeft != postEnd; postOrderLeft++) {
            if(*postOrderLeft == *(preStart+1)) {
                break;
            }
        }
        int sizeLeft = postOrderLeft - postStart + 1;
        root->left = rec(preStart+1, preStart+1+sizeLeft, postStart, postStart+sizeLeft);
        root->right = rec(preStart+sizeLeft+1, preEnd, postStart+sizeLeft, postEnd-1);
        return root;
    }
};