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
    // Helper function to delete nodes and build the forest
    TreeNode* delNodesHelper(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& ans) {
        if (!root) return nullptr;

        // Recursively delete nodes in left and right subtrees
        root->left = delNodesHelper(root->left, to_delete, ans);
        root->right = delNodesHelper(root->right, to_delete, ans);

        // If the current node needs to be deleted
        if (to_delete.count(root->val)) {
            // If the left child exists, add it as a new root
            if (root->left) ans.push_back(root->left);
            // If the right child exists, add it as a new root
            if (root->right) ans.push_back(root->right);
            // Return null to delete the current node
            return nullptr;
        }

        // Return the current node if it's not deleted
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        // Start the helper function with the root
        if (delNodesHelper(root, to_delete_set, ans) != nullptr) {
            ans.push_back(root); // If root is not deleted, add it to the forest
        }

        return ans; // Return the roots of the remaining trees
    }
};
