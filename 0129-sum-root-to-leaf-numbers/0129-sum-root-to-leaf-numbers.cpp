class Solution {
public:

    int dfs(TreeNode* node, int current_sum) {
        if (node == NULL) {
            return 0; 
        }

        current_sum = current_sum * 10 + node->val; 
        if (!node->left && !node->right) {
            return current_sum;
        }

        // Recurse on both left and right children, and return the sum of their results
        return dfs(node->left, current_sum) + dfs(node->right, current_sum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
