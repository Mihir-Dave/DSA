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
    
    // void heightleft(TreeNode* root , int cnt){
    //     if(root == NULL) return;
    //     if(root->left != NULL){
    //         cnt++;
    //         root = root->left;
    //     }
    //     if(root->right != NULL){
    //         cnt++;
    //         root = root->right;
    //     }

    // }
    //int cnt = 1;
    int height(TreeNode* root,int cnt){
        if(root == NULL) return 0;
        //if(root->left == NULL && root->right == NULL) ;
        if(root->left != NULL){
            cnt++;
            cnt = height(root->left,cnt);
        }
        if(root->right != NULL){
            cnt++;
            cnt = height(root->right,cnt);
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int cntl = 1;
        int cntr = 1;
        return 1+height(root->right,cntr)+height(root->left,cntl);
        //return 1+cntl+cntr;

    }
};