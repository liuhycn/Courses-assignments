class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), t;
        while (n > 1) 
        {
            t = 0;
            for (int i = 0; i < n; i += 2) 
                if (i == n - 1 || nums[i] == nums[i + 1]) nums[t++] = nums[i];
            n = t;
        }
        return nums[0];
    }
};