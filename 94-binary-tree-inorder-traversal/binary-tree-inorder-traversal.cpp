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
    typedef TreeNode* tr;
    typedef vector<int> vi;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vi ans;
        stack<tr> s;
        tr t = root;
        while(t || !s.empty()){
            while(t) {
                s.push(t);
                t = t->left;
            }
            if(s.empty()) {
                break;
            }
            t = s.top(); s.pop();
            ans.push_back(t->val);
            
            t = t->right;
        }
        return ans;
    }
};