/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
//  recursive dfs
//  class Solution {
//     public boolean isSameTree(TreeNode p, TreeNode q) {
//         if(p == null && q == null) return true;

//         if(p == null || q == null) return false;

//         if(p.val != q.val) return false;

//         return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
//     }
// }
//  interative bfs
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(p);
        queue.offer(q);

        while(!queue.isEmpty()){
            TreeNode t1 = queue.poll();
            TreeNode t2 = queue.poll();

            if(t1 == null && t2 == null) continue;
            if(t1 == null || t2 == null || t1.val != t2.val) return false;

            queue.offer(t1.left);
            queue.offer(t2.left);
            queue.offer(t1.right);
            queue.offer(t2.right);
        }
        return true;
    }
}