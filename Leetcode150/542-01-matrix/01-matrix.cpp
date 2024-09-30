
// class Solution {
// public:
//     void bfs(vector<vector<int>>& mat, int step, int x, int y)
//     {
//         int dx[4] = {0, 0, 1, -1};
//         int dy[4] = {1, -1, 0, 0};
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
//         visited[x][y] = true;  

//         while (!q.empty()) {
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();
//             step++;

//             for (int a = 0; a < 4; a++) {
//                 int xx = dx[a] + i;
//                 int yy = dy[a] + j;
//                 if (xx < 0 || yy < 0 || xx >= mat.size() || yy >= mat[0].size()) {
//                     continue;
//                 }
//                 if (mat[xx][yy] == 0) {
//                     mat[x][y] = step;
//                     return;
//                 }
//                 if (!visited[xx][yy]) {
//                     visited[xx][yy] = true;
//                     q.push({xx, yy});
//                 }
//             }
//         }
//     }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
//     {
//         // Iterate over the matrix and perform BFS for each non-zero element
//         for (int i = 0; i < mat.size(); i++) {
//             for (int j = 0; j < mat[i].size(); j++) {
//                 if (mat[i][j] != 0) {
//                     bfs(mat, 0, i, j);  
//                 }
//             }
//         }
//         return mat;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX)); // Initialize distances with a large number
        
        // Add all 0s to the queue and set their distance to 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Directions for moving in the grid (right, left, down, up)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        // Multi-source BFS from all 0s
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int a = 0; a < 4; a++) {
                int xx = x + dx[a];
                int yy = y + dy[a];
                
                // Check if the new position is within bounds and update distance if necessary
                if (xx >= 0 && yy >= 0 && xx < rows && yy < cols && dist[xx][yy] > dist[x][y] + 1) {
                    dist[xx][yy] = dist[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
        
        return dist;
    }
};

