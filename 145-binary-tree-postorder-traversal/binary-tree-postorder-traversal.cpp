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
    vector<int> postorderTraversal(TreeNode* root) {
        //using Morris traversal

        vector<int> ans ;

        TreeNode* curr = root ;
        while(curr != nullptr){
            if(curr->right == nullptr){
                ans.push_back(curr->val) ;
                curr = curr->left ;
            }
            else{
                TreeNode* pre = curr->right ; 
                while(pre->left != NULL && pre->left != curr){
                    pre = pre->left ;
                }

                if(pre->left == NULL){
                    ans.push_back(curr->val) ;
                    pre->left = curr ; 
                    curr = curr->right ; 
                }
                else{
                    pre->left = NULL ; 
                    curr = curr->left ;
                }
            }
        }

        reverse(ans.begin() , ans.end()) ;
        return ans ; 
    }
};