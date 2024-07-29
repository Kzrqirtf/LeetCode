// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    // {node, {hd, level}}
    queue<pair<TreeNode*, pair<int, int>>> q;
    // {hd, {level, value}}
    map<int, vector<pair<int, int>>> mpp;
    vector<vector<int>> ans;
    
    if (root == NULL) return ans;
    
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        TreeNode* node = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        
        mpp[hd].push_back({level, node->val});
        
        if (node->left) {
            q.push({node->left, {hd - 1, level + 1}});
        }
        
        if (node->right) {
            q.push({node->right, {hd + 1, level + 1}});
        }
    }
    
    for (auto it : mpp) {
        auto& vec = it.second;
        sort(vec.begin(), vec.end());
        vector<int> col;
        for (auto& p : vec) {
            col.push_back(p.second);
        }
        ans.push_back(col);
    }
    
    return ans;
}
};
