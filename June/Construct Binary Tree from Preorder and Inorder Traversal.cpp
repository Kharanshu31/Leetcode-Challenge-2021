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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil (preorder, inorder, 0, inorder.size()-1, 0);
    }
    
    TreeNode* buildTreeUtil (vector<int>& preorder, vector<int>& inorder, int iStart, int iEnd, int preInd) {
        if (preInd>=preorder.size() || iStart>iEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preInd]);
        
        int inInd=iStart;
        for (; inInd<=iEnd; inInd++) {
            if (inorder[inInd]==preorder[preInd]) break;
        }

        root->left=buildTreeUtil (preorder, inorder, iStart, inInd-1, preInd+1);
        root->right=buildTreeUtil (preorder, inorder, inInd+1, iEnd, preInd+1+inInd-iStart);
        return root;
    }
};
