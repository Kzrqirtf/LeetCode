
class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;  
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && !vis[i]) {  
                dfs(i, isConnected, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  
        vector<int> vis(V, 0);  
        int ans = 0;  
        
        for(int i = 0; i < V; i++) {  
            if(vis[i] == 0) {  
                ans++;  
                dfs(i, isConnected, vis);  
            }
        }
        return ans;
    }
};
