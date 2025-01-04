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
        int findLeftHeight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    int findRightHeight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }

public:
    int countNodes(TreeNode* root) {

        int lh = findLeftHeight(root) ;
        int rh = findRightHeight(root) ;
        if(lh != rh){
            lh = countNodes(root->left) ;
            rh = countNodes(root->right) ;
            return 1+lh+rh ;
        }

        return pow(2 , lh) -1 ;
        
    }
};