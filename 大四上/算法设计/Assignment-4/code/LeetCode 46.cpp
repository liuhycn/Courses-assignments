class Solution {
public:
    int len;
    vector<vector<int>> ans;
    void dfs(vector<int> cur, set<int> buf)
    {
        if (cur.size() == len)
        {
            ans.push_back(cur);
            return;
        }
        for (auto item : buf)
        {
            set<int> tmp = set<int>(buf);
            cur.push_back(item);
            tmp.erase(item);
            dfs(cur, tmp);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        set<int> num;
        for (auto item : nums)
        {
            num.insert(item);
        }
        vector<int> a;
        dfs(a, num);
        return ans;
    }
};