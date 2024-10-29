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
    vector<TreeNode*> buildTree(int l, int r) {
        vector<TreeNode*> tree;
        if (l > r) {
            tree.push_back(nullptr);
            return tree;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> leftSuns = buildTree(l, i-1);
            vector<TreeNode*> rightSuns = buildTree(i+1, r);
            for (TreeNode* left : leftSuns) {
                for (TreeNode* right : rightSuns) {
                    TreeNode* root = new TreeNode(i, left, right);
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
};
