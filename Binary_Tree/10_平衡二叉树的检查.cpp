// ====================================
// 平衡二叉树的检查  leetcode 110
// ====================================


// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。


class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	// 空树也是平衡二叉树
        if(root==NULL) return true;
        // 递归检查左右子树
        return abs(depth(root->right) - depth(root->left)) < 2
               && (isBalanced(root->right)) 
               && (isBalanced(root->left));
    }

    // 求树的高度
    int depth(TreeNode * root){
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
     }
};