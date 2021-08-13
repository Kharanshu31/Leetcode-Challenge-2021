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
    vector<vector<int>>ans;
    
    void dfs(TreeNode* root,vector<int>&path,int target)
    {
        if(!root)
            return;
        
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(target==root->val)
            {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        dfs(root->left,path,target-root->val);
        dfs(root->right,path,target-root->val);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root,path,targetSum);
        return ans;
    }
};
