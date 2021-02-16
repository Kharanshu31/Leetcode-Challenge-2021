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
    vector<int>ans;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            ans.push_back(q.back()->val);
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return ans;
    }
};
