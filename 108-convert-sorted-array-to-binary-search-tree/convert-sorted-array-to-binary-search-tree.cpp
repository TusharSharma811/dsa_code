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

TreeNode* solve(int start, int end , vector<int>& nums){
    if(start > end){
        return nullptr ;
    }
    int indx = start + (end - start )/2 ;
    TreeNode* temp = new TreeNode(nums[indx]) ;
    temp->left = solve( start , indx-1, nums) ;
    temp->right = solve( indx+1 ,end , nums) ;
    return temp ;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() ;
        TreeNode* root =solve(0 , n-1 , nums) ;
        return root ;
    }
};