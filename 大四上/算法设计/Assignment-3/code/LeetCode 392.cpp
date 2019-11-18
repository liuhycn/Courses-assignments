class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int m = s.size(), n = t.size();
        for(int i = 0,j = 0; j < n; j++)
        {
          if(s[i] == t[j]) i ++;
          if(i == m) return true;
        }
        return false;
    }
};