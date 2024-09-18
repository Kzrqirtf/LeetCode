class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int ini = image[sr][sc];
        if (ini == color) return;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        // vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            image[i][j]=color;
            q.pop();
            for(int a = 0; a < 4; ++a){
                int nx = i + dx[a], ny = j + dy[a];
                if(nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size() || image[nx][ny] != ini)
                    continue;
                // if(!vis)
                q.push({nx,ny});
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        bfs(ans,sr,sc,color);
        return ans;
    }
};