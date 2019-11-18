class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        ans.push_back({});
        for (int i = 0; i < len; i++)
        {
            if (i - 1 >= 0 && nums[i - 1] == nums[i])
            {
                for (auto &item : tmp)
                {
                    item.push_back(nums[i]);
                    ans.push_back(item);
                }
            }
            else
            {
                tmp = ans;
                for (auto &item : tmp)
                {
                    item.push_back(nums[i]);
                    ans.push_back(item);
                }
            }
        }
        return ans;
    }
};