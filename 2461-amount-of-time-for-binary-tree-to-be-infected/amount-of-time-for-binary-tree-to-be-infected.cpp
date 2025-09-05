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

   void childToParentMapping(unordered_map<int,TreeNode*>& mpp, TreeNode* root, TreeNode*& target, int start) {
        if (!root) return;
        if (root->val == start) target = root;

        if (root->left) {
            mpp[root->left->val] = root;
            childToParentMapping(mpp, root->left, target, start);
        }
        if (root->right) {
            mpp[root->right->val] = root;
            childToParentMapping(mpp, root->right, target, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode*> mpp ;
        TreeNode* target = NULL ;
        childToParentMapping(mpp , root , target , start) ;

        queue<TreeNode*> q ;
        q.push(target) ;
         unordered_map<int, bool> vis;
        vis[target->val] = true;

        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();

                // left child
                if (node->left && !vis[node->left->val]) {
                    q.push(node->left);
                    vis[node->left->val] = true;
                }
                // right child
                if (node->right && !vis[node->right->val]) {
                    q.push(node->right);
                    vis[node->right->val] = true;
                }
                // parent
                if (mpp.find(node->val) != mpp.end() && !vis[mpp[node->val]->val]) {
                    q.push(mpp[node->val]);
                    vis[mpp[node->val]->val] = true;
                }
            }
            ans++;
        }
        return ans - 1;

    }
};