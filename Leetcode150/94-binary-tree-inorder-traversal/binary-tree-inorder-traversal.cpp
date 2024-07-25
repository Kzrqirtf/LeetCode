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
    // void inorder(TreeNode* root,vector<int>&vect)
    // {
    //     if(root==NULL)return;
    //     inorder(root->left,vect);
    //     vect.push_back(root->val);
    //     inorder(root->right,vect);
    // }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        // inorder(root,result);
        // return result;   
        //Morris Inorder traversal
        TreeNode* cur=root;
        while(cur){
            if(cur->left==NULL)
            {
                result.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode *prev = cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    result.push_back(cur->val);
                    prev->right=NULL;
                    cur=cur->right;

                }
            }
        }
        return result;

    }
};