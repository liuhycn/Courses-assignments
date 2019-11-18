class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left && root->right && root->left->val == root->right->val)
        {
            TreeNode* temp1 = new TreeNode(0);
            temp1->left = root->left->right;
            temp1->right = root->right->left;
            TreeNode* temp2 = new TreeNode(0);
            temp2->left = root->left->left;
            temp2->right = root->right->right;
            return isSymmetric(temp1) && isSymmetric(temp2);
        }
        else return false;
    }
    
};