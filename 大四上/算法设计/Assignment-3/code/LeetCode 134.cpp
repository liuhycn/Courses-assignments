class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> sum = vector<int>(n * 2, 0);
        for (int i = 0; i < n * 2; i++)
            sum[i] = gas[i % n] - cost[i % n];

        int start = 0, end = 0, cur = 0;
        while (start < n && end <= 2 * n) 
        {
            cur += sum[end];
            while (cur < 0) {
                cur -= sum[start];
                start++;
            }
            if (end - start + 1 == n)
                return start;
            end++;
        }
        return -1;
    }
};