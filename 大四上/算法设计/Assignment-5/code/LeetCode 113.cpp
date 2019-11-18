class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (!root) return ans;
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum)
    { 
        path.push_back(root->val);
        sum -= root->val;
        if (root->left || root->right)
        {
            if (root->left) dfs(root->left, sum);
            if (root->right) dfs(root->right, sum);
        }
        else
        {
            if (!sum)
            {
                ans.push_back(path);
            }
        }
        path.pop_back();
    }
};