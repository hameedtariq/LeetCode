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
    int getMinimumDifference(TreeNode* root) {
        int last = -1;
        return LVR(root,last);
    }
    int LVR(TreeNode* root,int& prev){
        int mn = INT_MAX;
        if(!root) return mn;
        mn = LVR(root->left, prev);
        if(prev != -1){
            mn = min(abs(root->val-prev),mn);
        }
        prev = root->val;
        mn = min(LVR(root->right,prev), mn);
        return mn;
    }
    
};

// if(!root) return INT_MAX;
        // int mn = INT_MAX;
        // if(root->left){
        //     LVR(root->left,cont);
        // }
        // cont.push_back(root->val);
        // LVR(root->right,cont);