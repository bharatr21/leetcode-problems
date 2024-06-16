class Node {
    public:
        Node *left, *right;
        int sum;
        int L;
        int R;
        Node(int val, int l, int r) {
            sum = val;
            L = l;
            R = r;
            left = NULL;
            right = NULL;
        }
};

class NumArray {
public:
    Node* root;
    NumArray(vector<int>& nums) {
       root = build(nums, 0, nums.size() - 1);
    }

    Node* build(vector<int>& nums, int l, int r) {
        if (l == r)
            return new Node(nums[l], l, r);

        int m = l + (r - l) / 2;
        Node* root = new Node(0, l, r);
        root->left = build(nums, l, m);
        root->right = build(nums, m + 1, r);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    void update(int index, int val) {
        updateHelper(root, index, val);
    }

    void updateHelper(Node* root, int index, int val) {
        if(root->L == root->R) {
            root->sum = val;
            return;
        }

        int M = (root->L + (root->R  - root->L) / 2);
        if(index > M)
            updateHelper(root->right, index, val);
        else
            updateHelper(root->left, index, val);

        root->sum = root->left->sum + root->right->sum;
    }
    
    int sumRange(int left, int right) {
        return sumHelper(root, left, right);
    }

    int sumHelper(Node* root, int left, int right) {
        if(root->R < left || root->L > right) return 0;
        else if(left <= root->L && root->R <= right) return root->sum;
        else return sumHelper(root->left, left, right) + sumHelper(root->right, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */