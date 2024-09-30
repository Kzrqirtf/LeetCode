class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        // visited and distance matrix
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> dist(n, vector<int>(m, 0)); 
        
        // <coordinates, steps>
        queue<pair<pair<int,int>, int>> q; 

        // Traverse the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Start BFS if cell contains 0
                if(grid[i][j] == 0) {
                    q.push({{i, j}, 0}); 
                    vis[i][j] = 1;  // mark visited
                } else {
                    // Mark unvisited for non-zero cells
                    vis[i][j] = 0; 
                }
            }
        }
        
        // Possible directions: up, right, down, left
        int delrow[] = {-1, 0, +1, 0}; 
        int delcol[] = {0, +1, 0, -1}; 
        
        // Traverse till queue becomes empty
        while(!q.empty()) {
            int row = q.front().first.first; 
            int col = q.front().first.second; 
            int steps = q.front().second; 
            q.pop(); 
            
            dist[row][col] = steps;  // Set the distance of the current cell
            
            // For all 4 neighbors (up, right, down, left)
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                
                // Check if neighbor is within bounds and unvisited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;  // Mark as visited
                    q.push({{nrow, ncol}, steps + 1});  // Add to queue with incremented steps
                }
            }
        }
        
        // Return the distance matrix
        return dist; 
    }
};
