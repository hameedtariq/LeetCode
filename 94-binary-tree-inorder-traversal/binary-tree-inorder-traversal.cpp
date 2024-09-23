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
        if(!root) return vector<int>();
        vi ans;
        stack<t> s;
        s.push(root);
        while(!s.empty()){
            t p = s.top();
            if(p->left){
                s.push(p->left);
                p->left = nullptr;
            }else if(p->right) {
                ans.push_back(p->val);
                s.pop();
                s.push(p->right);
                p->right = nullptr;
            }else {
                ans.push_back(p->val);
                s.pop();
            }
        }
        return ans;
    }
};