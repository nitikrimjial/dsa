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
    bool issame(TreeNode* s, TreeNode* p) {
        if(!s && !p){
            return true;
        }
        if(!s || !p){
            return false;
        }
        return  s -> val == p -> val && issame(s -> left, p -> left) && issame(s -> right, p -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub){
        if(!sub){
            return true;
        }
        if(!root){
            return false;
        }
        if(issame(root, sub)){
            return true;
        }
        return isSubtree(root -> left, sub) || isSubtree(root -> right, sub);
    }
};