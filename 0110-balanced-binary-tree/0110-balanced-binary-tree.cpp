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
  int dfsheight(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lleft= dfsheight(root->left);
       if(lleft==-1) return -1;
        int rright=dfsheight(root->right);
       if (rright==-1) return -1;
        if (abs(rright-lleft)>1) return -1;
         return 1+ max(lleft,rright);

    }
    bool isBalanced(TreeNode* root) 
    {
        return dfsheight(root) !=-1;
    }
  
};