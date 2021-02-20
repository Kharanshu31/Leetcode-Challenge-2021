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
    void swap(TreeNode* root)
    {
        if(root)
        {
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
            
            swap(root->left);
            swap(root->right);
        }
    }
    
    int sum=0;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        sum+=root->val;
        root->val=sum;
        dfs(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        swap(root);
        dfs(root);
        swap(root);
        return root;
    }
};
