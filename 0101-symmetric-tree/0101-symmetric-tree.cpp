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
    bool helper(TreeNode* lh,TreeNode* rh) {

        //check if root has no child then single root is symmetric
        if(lh == NULL && rh == NULL) {
            return true;
        }

        //check if one of the child node is null and other is not then is isn't symmetric 
        if(lh == NULL || rh == NULL) {
            return false;
        }

        //recursive call for left and right subtree as well as checking the value of left and right node
        return lh -> val == rh -> val && helper( lh -> left , rh -> right ) && helper( lh -> right,rh -> left );
    }
    bool isSymmetric(TreeNode* root) { 

        //check if root is null
        if(root == NULL) return true;

        //check if root has no child then single root is symmetric 
        if( (root -> left == NULL) && (root -> right == NULL) ) return true;

        //check if one of the child node is null and other is not then is isn't symmetric 
        if( (root -> left == NULL) || (root -> right == NULL) ) return false;

        //recursive call for left and right subtree as well as checking the value of left and right node
        return helper ( root -> left , root -> right ) &&  root -> left -> val == root -> right -> val;
    }
};