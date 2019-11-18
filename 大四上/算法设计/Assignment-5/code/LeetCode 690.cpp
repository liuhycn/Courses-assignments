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