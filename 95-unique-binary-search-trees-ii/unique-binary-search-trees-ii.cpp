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
private:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {NULL};
        }

        if (memo.find(start * 100 + end) != memo.end()) {
            return memo[start * 100 + end];
        }

        vector<TreeNode*> result;

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        memo[start * 100 + end] = result;
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        // vector<TreeeNode*> ans;
        if(n == 0) return {};
        return generateTrees(1,n);
    }
};