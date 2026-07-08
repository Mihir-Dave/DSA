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
    bool func(TreeNode* rr, TreeNode* lr){
        if(rr == NULL && lr == NULL){
            return true;
        }
        if(rr == NULL|| lr == NULL){
            return false;
        }
        return ((rr->val == lr->val)&&func(rr->left, lr->right)&&func(rr->right, lr->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return func(root->right,root->left);
    }
};