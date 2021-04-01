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
    bool flag=true;
    int i=0;
    void dfs(TreeNode* root,TreeNode* parent ,vector<int>& voyage)
    {
        if(!root)
            return;
        
        cout<<root->val<<"  "<<i<<"\n";
        
        if(voyage[i++]!=root->val)
        {
            flag=false;
            return;
        }
        
        if(root->left && root->right)
        {
            if(root->left->val!=voyage[i])
            {
                ans.push_back(root->val);
                swap(root->left,root->right);
            }
        }
        
        dfs(root->left,root,voyage);
        dfs(root->right,root,voyage);
        
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root,NULL,voyage);
        if(!flag)
            return {-1};
        return ans;
    }
};
