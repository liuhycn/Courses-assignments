class NumArray {
public:
    vector<int>f;
    NumArray(vector<int> nums) 
    {
        int n = nums.size();
        f = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i ++ ) f[i] = f[i - 1] + nums[i - 1];
    }

    int sumRange(int i, int j) {
        return f[j + 1] - f[i];
    }
};