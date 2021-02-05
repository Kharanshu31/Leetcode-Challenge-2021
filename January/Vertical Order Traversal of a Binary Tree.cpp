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
    void vertical(TreeNode* root, int x, int y, map<int,vector<pair<int, int>>>&m)
    {
        if(!root)
            return;
        m[x].push_back(make_pair(y,root->val));
        if(root->left)
            vertical(root->left,x-1,y+1,m);
        if(root->right)
            vertical(root->right,x+1,y+1,m);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        map<int,vector<pair<int, int>>>m;
        vertical(root,0,0,m);
        
        for(auto i:m)
        {
            sort(i.second.begin(), i.second.end());
            vector<int>r;
            
            for(int j=0;j<i.second.size();j++)
            {
                r.push_back(i.second[j].second);
            }
            
            ans.push_back(r);
            
        }
        
        return ans;
    }
};
