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
    int final_sum=0;
    void preorder(TreeNode* root,int cur)
    {
        if(!root)
            return ;
        if(!root->left && !root->right)
        {
            final_sum+=10*cur+root->val;
            return;
        }
        
        preorder(root->left,cur*10+root->val);
        preorder(root->right,cur*10+root->val);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        preorder(root,0);
        
        return final_sum;
    }
};
