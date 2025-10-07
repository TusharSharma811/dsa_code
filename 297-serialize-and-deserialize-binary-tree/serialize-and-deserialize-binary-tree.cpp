/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.




    string serialize(TreeNode* root) {
        if (!root) return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserializeHelper(vector<string>& nodes, int& i) {
        if (i >= nodes.size() || nodes[i] == "#") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[i++]));
        node->left = deserializeHelper(nodes, i);
        node->right = deserializeHelper(nodes, i);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> nodes;
        string token;
        while (ss >> token)
            nodes.push_back(token);

        int i = 0;
        return deserializeHelper(nodes, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));