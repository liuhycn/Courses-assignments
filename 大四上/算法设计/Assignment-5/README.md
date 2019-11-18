### LeetCode 104. Maximum Depth of Binary Tree

（递归） $$O(n)$$

1. 当前树的最大深度等于左右子树的最大深度加1。

#### 代码

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
```

#### 结果

![BDCCE0E4-2DD8-4FBB-BEC2-F3A2B6CA41DE](img/BDCCE0E4-2DD8-4FBB-BEC2-F3A2B6CA41DE.png)

### LeetCode 101. Symmetric Tree

（递归）$$O(n)$$

1. 递归判断两个子树是否互为镜像。
2. 两个子树互为镜像当且仅当：
   - 两个子树的根节点值相等；
   - 第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像；

#### 代码

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left && root->right && root->left->val == root->right->val)
        {
            TreeNode* temp1 = new TreeNode(0);
            temp1->left = root->left->right;
            temp1->right = root->right->left;
            TreeNode* temp2 = new TreeNode(0);
            temp2->left = root->left->left;
            temp2->right = root->right->right;
            return isSymmetric(temp1) && isSymmetric(temp2);
        }
        else return false;
    }
    
};
```

#### 结果

![EEA647C3-9A3D-4587-9732-43CFA93EFE5A](img/EEA647C3-9A3D-4587-9732-43CFA93EFE5A.png)

### LeetCode 733. Flood Fill 

（递归）$$O(n)$$

1. 当前点`(x,y)`的四周可以借助两个数组来表示，`dx[4] = {-1, 0, 1, 0}`, `dy[4] = {0, 1, 0, -1}`，那么四周的坐标分别是`x=sr+dx[i]`,`y=sc+dy[i]`,`i=0,1,2,3`。
2. 依次检查当前点的四个邻接点是否满足条件（颜色一样），是的话递归调用`floddFill()`

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int rawColor = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i ++ )
        {
            int x = sr + dx[i], y = sc + dy[i];
            if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == rawColor)
                floodFill(image, x, y, newColor);
        }
        return image;
    }
};
```

#### 结果

![2E38D900-7935-4C47-A1A8-3119DC461755](img/2E38D900-7935-4C47-A1A8-3119DC461755.png)

### LeetCode 111. Minimum Depth of Binary Tree

（递归）$$O(n)$$

1. 对于每个节点：
   - 如果没有子节点，说明是叶节点，则返回1；
   - 如果有子节点，说明是内部结点，则返回子节点的深度的最小值 + 1（加上根节点这层）；

### 代码

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        if (root->left) res = min(res, minDepth(root->left) + 1);
        if (root->right) res = min(res, minDepth(root->right) + 1);
        if (res == INT_MAX) res = 1;
        return res;
    }
};
```

#### 结果

![0A58CD96-870F-4486-AB4D-46EDAEFAF03D](img/0A58CD96-870F-4486-AB4D-46EDAEFAF03D.png)

### LeetCode 690. Employee Importance

（递归）$$O(n)$$

1. 首先遍历员工数组，用`map`记录每个员工`id`对应的信息；
2. 对于给定的员工`id`，他的价值等于以下之和：
   - 自身价值；
   - 下属价值之和（DFS）；

### 代码

```c++
class Solution {
public:
    unordered_map<int, Employee*> mymap;
    int dfs(int x)
    {
        if (mymap.find(x) == mymap.end()) return 0;
        int res = 0;
        auto e = mymap[x];
        res += e->importance;
        for (auto subid : e->subordinates)
            res += dfs(subid);
        
        return res;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto item : employees)
            mymap[item->id] = item;
        
        return dfs(id);
    }
    
};
```

#### 结果

![79EDFD8A-F840-4A52-83E0-4F1F11419BAA](img/79EDFD8A-F840-4A52-83E0-4F1F11419BAA.png)

### LeetCode 841. Keys and Rooms

（递归） $$O(n+m)$$

1. 从 0 号房间开始`DFS`，房中的钥匙看做是相邻的有向边。
2. 用 `vis` 数组记录，保证每个点最多只进入一次。

### 代码

```c++
class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> buf;
    void dfs(int x)
    {
        vis[x] = true;
        for (int i = 0; i < buf[x].size(); i ++)
        {
            int v = buf[x][i];
            if (!vis[v])
            {
                dfs(v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        buf = rooms;
        vis.resize(n, false);
        dfs(0);
        for (int i = 0; i < n; i++)
            if (!vis[i]) return false;
        return true;
    }
};
```

#### 结果

![B5FD8ABA-AD7D-43CF-BD34-3E4A9432EC76](img/B5FD8ABA-AD7D-43CF-BD34-3E4A9432EC76.png)

### LeetCode 113. Path Sum II

（递归） $$O(n^2)$$

1. 递归，自顶向下从根节点往叶节点走；
2. 每走过一个节点，就让 `sum` 减去该节点的值;
3. 如果走到某个叶节点时，`sum` 恰好为`0`，则说明从根节点到这个叶节点的路径上的数的和等于 `sum`，此时需要把这条路径记录下来。

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (!root) return ans;
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum)
    { 
        path.push_back(root->val);
        sum -= root->val;
        if (root->left || root->right)
        {
            if (root->left) dfs(root->left, sum);
            if (root->right) dfs(root->right, sum);
        }
        else
        {
            if (!sum)
            {
                ans.push_back(path);
            }
        }
        path.pop_back();
    }
};
```

#### 结果

![537408E7-7CA0-4AAE-9DA9-A8F9A0A43AB2](img/537408E7-7CA0-4AAE-9DA9-A8F9A0A43AB2.png)