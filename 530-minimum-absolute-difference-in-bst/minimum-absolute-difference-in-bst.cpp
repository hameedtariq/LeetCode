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
        // int minL = INT_MAX, minR=INT_MAX;
        // if(root->left){
        //     minL = min(abs(root->val - root->left->val),getMinimumDifference(root->left));
        // }
        // if(root->right){
        //     minR = min(abs(root->val - root->right->val),getMinimumDifference(root->right));
        // }
        // return min(minL,minR);

        // inorder traversal and check neighbouring differences!
        // LVR
        vector<int> container;
        LVR(root, container);
        int n = container.size(), mn = INT_MAX;
        for(int i =0; i< n-1; i++){
            mn = min(mn,abs(container[i]-container[i+1]));
        }
        return mn;
    }
    void LVR(TreeNode* root,vector<int>& cont){
        if(!root) return;
        LVR(root->left,cont);
        cont.push_back(root->val);
        LVR(root->right,cont);
    }
    
};