#include <string>
#include <sstream>

class Codec {
public:
    void serialrecur(TreeNode* root, std::stringstream& ss) {
        if (!root) {
            ss << "null,";
            return;
        }
        ss << root->val << ',';
        serialrecur(root->left, ss);
        serialrecur(root->right, ss);
    }

    std::string serialize(TreeNode* root) {
        std::stringstream ss;
        serialrecur(root, ss);
        return ss.str();
    }

    TreeNode* deserialrecur(std::stringstream& ss) {
        std::string token;
        if (!std::getline(ss, token, ',')) return nullptr;
        if (token == "null") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(token));
        node->left = deserialrecur(ss);
        node->right = deserialrecur(ss);
        return node;
    }

    TreeNode* deserialize(const std::string& data) {
        std::stringstream ss(data);
        return deserialrecur(ss);
    }
};
