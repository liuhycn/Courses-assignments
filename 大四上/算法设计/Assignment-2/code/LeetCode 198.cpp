class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int f = nums[0], g = 0;

        for (int i = 1; i < n; i++)
        {
            int last_f = f, last_g = g;
            f = g + nums[i];
            g = max(last_f, last_g);
        }
        return max(f, g);
    }
};