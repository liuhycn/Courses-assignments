class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> s;
        for(int i = 0; i < obstacles.size(); i ++)
        {
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            s.insert({x, y});
        }
        int direction = 1;
        int axis = 1;
        int posx = 0;
        int posy = 0;
        int res = 0;
        for(int i = 0; i < commands.size(); i ++)
        {
            if(commands[i] == -1)
            {
                if(axis == 0) direction *= -1;
                axis = (axis + 1) % 2;
            }
            else if (commands[i] == -2)
            {
                if(axis == 1) direction *= -1;
                axis = (axis + 1) % 2;
            }
            else if(commands[i] > 0)
            {
                if(axis == 0)
                {
                    while(commands[i] --)
                    {
                        posx += direction;
                        if(s.find({posx, posy}) != s.end())
                        {
                            posx -= direction;
                            break;
                        }
                    }
                }
                if(axis == 1)
                {
                    while(commands[i] --)
                    {
                        posy += direction;
                        if(s.find({posx, posy}) != s.end())
                        {
                            posy -= direction;
                            break;
                        }
                    }
                }
                int dist = posx * posx + posy * posy;
                if(dist > res) res=dist;
            }
        }
        return res;
    }
};