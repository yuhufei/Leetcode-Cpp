
// ========================================
//  将有序数组转换成二叉搜索树  leetcode 108
// ========================================
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

// 二叉搜索树的定义是左子树均小于根节点，柚子树均大于根节点
// 左右子树又分别是二叉搜索树

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right){
    	// 起始位置大于结束为止，返回空
        if(left > right) return nullptr;
        // 将有序数组的中间值作为根节点
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // 递归构建左子树
        root->left = helper(nums, left, mid-1);
        // 递归构建柚子树
        root->right = helper(nums, mid+1, right);
        return root;
    }
};