### LeetCode 70. Climbing Stairs

（递推）$$O(n)$$

1. 定义数组 `dp[i]`：表示上` i` 级台阶的方案数.
2. 则枚举最后一步是上1级台阶，还是上2级台阶，所以有:`dp[i] = dp[i−1] + dp[i−2]`。

#### 时间复杂度

- 递推状态数 $$O(n)$$
- 转移时间复杂度是 $$O(1)$$
- 总时间复杂度是 $$O(n)$$

#### 代码

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i ++ )
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
```

#### 结果

![CD10C5EF-353C-4EB9-BC6A-B5BF60B4FDE1](img/CD10C5EF-353C-4EB9-BC6A-B5BF60B4FDE1.png)

### LeetCode 121. Best Time to Buy and Sell Stock

（贪心）$$O(n)$$

1. 选当前最优。遍历一次，更新当前最低价格和最高利润。

#### 时间复杂度

- 扫描一遍，故时间复杂度为$$O(n)$$。

#### 代码

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0, low = prices[0];
        for(int i = 1; i < prices.size(); i ++)
        {
            profit = max(profit, prices[i] - low);
            low = min(low, prices[i]);
        }
        return profit;
    }
};
```

#### 结果

![AA6143CB-56D5-4750-9096-29FC8E686004](img/AA6143CB-56D5-4750-9096-29FC8E686004.png)

### LeetCode 746. Min Cost Climbing Stairs

（动态规划）$$O(n)$$

1. 定义数组`dp[i]`，大小为`cost.size()`，用于记录到达第`i`层所需的最小体力。 
2. 初始化`dp[0]`和`dp[1]`。
3. 后面每次都选择`min(dp[i - 1], dp[i - 2])`再加上到这一级所需的体力。 
4. 最后要求的是到达顶部所需的体力，根据题意，只要到达最后1级或倒数第2级就可以了。

#### 时间复杂度

- #### 时间复杂度

  - 递推状态数 $$O(n)$$
  - 转移时间复杂度是 $$O(1)$$
  - 总时间复杂度是 $$O(n)$$

#### 代码

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i ++)
        {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};
```

#### 结果

![1140B0EB-B588-4C87-A80E-528BD8E18E6D](img/1140B0EB-B588-4C87-A80E-528BD8E18E6D.png)

### LeetCode 198. House Robber

（动态规划）$$O(n)$$

1. 令`f[i]`表示盗窃了第`i`个房间所能得到的最大收益，`g[i]`表示不盗窃第`i`个房间所能得到的最大收益。
2. `f[i] = g[i - 1] + nums[i]`，`g[i] = max(f[i - 1], g[i - 1])`。
3. 初始值`f[0] = nums[0], g[0] = 0`，答案为`max(f[n - 1], g[n - 1])`。

#### 时间复杂度

- 递推状态数 $$O(n)$$
- 转移时间复杂度是 $$O(1)$$
- 总时间复杂度是 $$O(n)$$

#### 代码

```c++
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
```

#### 结果

![89B55F2C-98E6-4F97-ABF6-4256060E417E](img/89B55F2C-98E6-4F97-ABF6-4256060E417E.png)

### LeetCode 303. Range Sum Query - Immutable

（前缀和） $$O(n)$$

1. 计算出`nums`数组的前缀和。
2. 求`sumRange(i, j)`时，直接返回` f[j]−f[i−1]`即可。

#### 时间复杂度

- 初始化时需要遍历整个数组，时间复杂度是$$ O(n)$$。
- 求区间和时只有常数次计算，时间复杂度是 $$O(1)$$。

#### 代码

```c++
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
```

#### 结果

![852B91EB-93CC-493F-B78E-12B2EFAB7447](img/852B91EB-93CC-493F-B78E-12B2EFAB7447.png)

### LeetCode 62. Unique Paths

（动态规划)）$$O(mn)$$

1. 动态规划数组`dp[i][j]` 代表起点到点`(i, j)`的路径总数。
2. 递推关系式：`dp[i][j] = dp[i][j-1] + dp[i-1][j]`。
3. 再考虑边界情况，当`i == 1 || j == 1`时，`dp[i][j] = 1`。

#### 时间复杂度

- 上述做法需要一个大小为`m x n`的二维数组。
- 故时间复杂度为$$O(mn)$$。

#### 代码

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {  
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 || j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }  
};
```

#### 结果

![B9211288-7670-4F25-867C-D771A72ADE8B](img/B9211288-7670-4F25-867C-D771A72ADE8B.png)

### LeetCode 64. Minimum Path Sum

（动态规划）$$O(mn)$$

1. 用`dp[i][j]`记录到达网格`grid[i][j]`位置经过的最小的路径和。
2. 转移方程为`dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`。

#### 时间复杂度

- 上述做法需要一个大小为`m x n`的二维数组。
- 故时间复杂度为$$O(mn)$$。

#### 代码

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i > 0) dp[i][j] = dp[i - 1][j];
                if(j > 0)
                    if(i == 0) dp[i][j] = dp[i][j - 1];
                    else dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                
                dp[i][j] += grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

#### 结果

![02EC9BC3-0ACE-4C74-97B3-4C3A0E5806F4](img/02EC9BC3-0ACE-4C74-97B3-4C3A0E5806F4.png)