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