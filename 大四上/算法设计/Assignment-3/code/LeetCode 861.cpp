class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < n; i ++)
            if (A[i][0] == 0)
                for (int j = 0; j < m; j ++) A[i][j] = 1 - A[i][j];
            
        for (int j = 1; j < m; j ++)
        {
            int cnt = 0;
            for (int i = 0; i < n; i ++) cnt += A[i][j];
            if (cnt <= n / 2)
            		for (int i = 0; i < n; i ++) A[i][j] = 1 - A[i][j];
        }

        int ans = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                ans += A[i][j] << (m - j - 1);
        return ans;
    }
};