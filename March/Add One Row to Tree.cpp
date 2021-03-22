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
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode *t=new TreeNode(v);
            t->left=root;
            return t;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(level<d-1)
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* f=q.front();
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            level++;
        }
        
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            TreeNode* l=cur->left;
            TreeNode* r=cur->right;
            cur->left=new TreeNode(v);
            cur->right=new TreeNode(v);
            cur->left->left=l;
            cur->right->right=r;
        }
        return root;
    }
};
