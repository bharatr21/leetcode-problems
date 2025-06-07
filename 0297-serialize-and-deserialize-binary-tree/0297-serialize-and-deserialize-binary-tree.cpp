class Codec {
public:
    void serialrecur(TreeNode* root, stringstream& ss) {
        if (!root) {
            ss << "null,";
            return;
        }
        ss << root->val << ',';
        serialrecur(root->left, ss);
        serialrecur(root->right, ss);
    }

    string serialize(TreeNode* root) {
        stringstream ss;
        serialrecur(root, ss);
        return ss.str();
    }

    TreeNode* deserialrecur(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',')) return nullptr;
        if (token == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserialrecur(ss);
        node->right = deserialrecur(ss);
        return node;
    }

    TreeNode* deserialize(const string& data) {
        stringstream ss(data);
        return deserialrecur(ss);
    }
};