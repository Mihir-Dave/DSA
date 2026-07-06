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
    //void check()
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: If both nodes are NULL, they are identical
        if (p == NULL && q == NULL) {
            return true;
        }
        
        // Case 2: If only one of the nodes is NULL, they are not identical
        if (p == NULL || q == NULL) {
            return false;
        }

        // Check if the current nodes have the same data value
        // and recursively check their left and right subtrees
        return ((p->val == q->val)
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right));
    }
};