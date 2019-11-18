class Solution {
public:
    vector<vector<int>> tmp;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            tmp = ans;
            for (auto &item : tmp)
            {
                item.push_back(nums[i]);
                ans.push_back(item);
            }
        }
        return ans;
    }
};