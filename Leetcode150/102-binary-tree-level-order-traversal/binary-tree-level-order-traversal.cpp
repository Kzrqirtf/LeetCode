/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levelcount(TreeNode* root)
    {
        if(root==NULL)return 0;
        return 1 + max(levelcount(root->left),levelcount(root->right));
        
    }
    void Level(TreeNode* root,int n,vector<int> &v)
    {
        if(root==NULL)return;
        if(n==0)v.push_back(root->val);
        else
            {
                Level(root->left,n-1,v);
                Level(root->right,n-1,v);    
            }      
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // int i=levelcount(root);
        // vector<vector<int>> v3;
        // for(int k=0;k<i;k++)
        // {
        //     vector<int> v;
        //     Level(root,k,v);
        //     v3.push_back(v);
        // }
        // return v3;
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes
        // for level-order traversal
        queue<TreeNode*> q; 
        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store
            // nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node value
                // in the current level vector
                level.push_back(node->val); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order
        // traversal of the tree
        return ans; 
    }
        
    
};