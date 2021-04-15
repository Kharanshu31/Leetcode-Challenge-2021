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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        vector<pair<int,int>>ans;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back({0,root->val});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left)
                {
                    q.push(t->left);
                    ans.push_back({level,t->left->val});
                }
                if(t->right)
                {
                    q.push(t->right);
                    ans.push_back({level,t->right->val});
                }
            }
            ++level;
        }
        
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        int mx=ans[0].first;
        int res=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].first==mx)
            {
                res+=ans[i].second;
            }
        }
        return res;
    }
};
