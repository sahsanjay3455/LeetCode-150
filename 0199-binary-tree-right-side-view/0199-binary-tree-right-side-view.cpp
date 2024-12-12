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
    void dfs(TreeNode* node, int depth, int& maxDepth, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // If this is the first node we visit at this depth, add it to the result
        if (depth > maxDepth) {
            result.push_back(node->val);
            maxDepth = depth;
        }

        // Prioritize the right subtree
        dfs(node->right, depth + 1, maxDepth, result);

        // Then explore the left subtree
        dfs(node->left, depth + 1, maxDepth, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int maxDepth = -1; // Keeps track of the maximum depth processed
        dfs(root, 0, maxDepth, result);
        return result;
    }
};