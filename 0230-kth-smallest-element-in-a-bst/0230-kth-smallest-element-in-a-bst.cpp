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
    void solve(TreeNode* root, int& count, int& res, int k){
        if(root == NULL){
            return ;
        }
        solve(root -> left, count, res, k);
        count++;
        if(count == k){
            res = root -> val;
            return ;
        }
        solve(root->right, count, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int res;
        solve(root, count, res, k);
        return res;

    }
};