class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int dx[4] = {0, 0, -1, +1};
        int dy[4] = {1, -1, 0, 0};
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int xx = i + dx[k];
            int xy = j + dy[k];
            if (xx >= 0 && xx < n && xy >= 0 && xy < m && !vis[xx][xy] && grid[xx][xy] == 1) {
                dfs(xx, xy, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the first and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, vis);
            }
        }

        // Traverse the first and last column (corrected loop)
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis);
            }
        }

        // Count the number of enclaves (1s not visited)
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
