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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>s1,s2;
        bool done1=false;
        bool done2=false;
        auto x=root;
        auto y=root;
        int val1=0,val2=0;
        while(true)
        {
            while(!done1)
            {
                if(x)
                {
                    s1.push(x);
                    x=x->left;
                }
                else
                {
                    if(!s1.empty())
                    {
                        x=s1.top();
                        s1.pop();
                        val1=x->val;
                        x=x->right;
                    }
                    done1=true;
                }
            }
            
            while(!done2)
            {
                if(y)
                {
                    s2.push(y);
                    y=y->right;
                }
                else
                {
                    if(!s2.empty())
                    {
                        y=s2.top();
                        s2.pop();
                        val2=y->val;
                        y=y->left;
                    }
                    done2=true;
                }
            }
            
            //cout<<" val1 : "<<val1<<"  VAL2 : "<<val2<<"\n";
            
            if(val1!=val2 && val1+val2==k)
                return true;
            
            if(val1+val2<k)
                done1=false;
            else
                done2=false;
            
            if(val1>=val2)
                break;
            
        }
        
        return false;
    }
};
