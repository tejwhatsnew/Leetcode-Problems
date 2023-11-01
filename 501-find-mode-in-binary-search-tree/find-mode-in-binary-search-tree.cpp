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
    vector<int> findMode(TreeNode* root) {
        map<int, int> countMap;
    stack<TreeNode*> nodes;
    TreeNode* current = root;
    int maxCount = 0;
    
    // Perform in-order traversal using a stack
    while (current || !nodes.empty()) {
        while (current) {
            nodes.push(current);
            current = current->left;
        }
        current = nodes.top();
        nodes.pop();
        countMap[current->val]++;
        maxCount = max(maxCount, countMap[current->val]);
        current = current->right;
    }
    
    vector<int> result;
    for (const auto& pair : countMap) {
        if (pair.second == maxCount) {
            result.push_back(pair.first);
        }
    }
    
    return result;
}

// Helper function to build a BST from an array
TreeNode* buildBST(vector<int>& arr, int left, int right) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);
    return root;
    }
};