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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int, int> res;
        for (int i = 0; i < inorder.size(); i++){
            res[inorder[i]] = i;
        }
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, res);
    
    }
    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &res){
        if(ps > pe || is > ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = res[postorder[pe]];
        int numsLeft = inRoot - is;
        root -> left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, res);
        root -> right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1 , res);
        return root;


    }
    
};