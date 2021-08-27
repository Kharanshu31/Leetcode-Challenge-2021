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
typedef long long ll;
class Solution {
public:
    ll tot=0,ans=0;
    void sum(TreeNode*root)
    {
        if(!root)
            return;
        tot+=root->val;
        sum(root->left);
        sum(root->right);
    }
    
    ll solve(TreeNode*root)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        
        ll l=solve(root->left);
        ll r=solve(root->right);
        //cout<<" l : "<<l<<" r : "<<r<<" root : "<<root->val<<"\n"; 
        ans=max(ans,max((l)*(tot-l),(r)*(tot-r)));
        return l+r+root->val;

    }
    int maxProduct(TreeNode* root) {
        tot=0;
        ans=0;
        sum(root);
        //cout<<" tot : "<<tot<<"\n";
        solve(root);
        ll mod=1e9+7;
        return ans%mod;
    }
};
