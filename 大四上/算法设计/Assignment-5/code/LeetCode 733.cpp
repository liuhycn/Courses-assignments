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