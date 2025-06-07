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
    void serialrecur(TreeNode* root, string& res) {
        if(!root) {res += "null,"; return;}
        res += to_string(root->val) + ',';
        serialrecur(root->left, res);
        serialrecur(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialrecur(root, res);
        return res;
    }

    TreeNode* deserialrecur(vector<string>& tree, int& idx) {
        if(tree[idx] == "null") {
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tree[idx++]));
        node->left = deserialrecur(tree, idx);
        node->right = deserialrecur(tree, idx);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tree;
        stringstream ss(data);
        string tmp;
        while(getline(ss, tmp, ',')) {
            tree.push_back(tmp);
        }
        int idx = 0;
        return deserialrecur(tree, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));