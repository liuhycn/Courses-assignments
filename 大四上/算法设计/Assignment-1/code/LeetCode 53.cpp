class Solution {
public:
    vector<int> nums;
    int dfs(int l, int r)
    {
        if (l == r) return nums[l];
        int mid = (long long)l + r >> 1;
        int lmax = nums[mid], lsum = 0, rmax = nums[mid + 1], rsum = 0;
        for (int i = mid; i >= l; i--) 
        {
            lsum += nums[i];
            lmax = max(lmax, lsum);
        }
        for (int i = mid + 1; i <= r; i++) 
        {
            rsum += nums[i];
            rmax = max(rmax, rsum);
        }
        return max(max(dfs(l, mid), dfs(mid + 1, r)), lmax + rmax);
    }
    int maxSubArray(vector<int>& tmp) {
        nums = tmp;
        return dfs(0, nums.size() - 1);
    }
};