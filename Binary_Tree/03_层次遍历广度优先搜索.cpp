// 层次遍历是二叉树的另一种重要的遍历方式之一
// 它是指从上到下，从左到右依次遍历二叉树的方式
// 与前中后遍历不同，二叉树的层次遍历是用队列实现的

// ================================
// 从上到下打印二叉树  Leetcode 32-I
// ================================

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
    	// 构建一个队列
        queue<TreeNode*> q;
        // 保存结果的容器
        vector<int> res;
        // 节点为空则返回空容器
        if(root==NULL) return res;
        // 根节点入队
        q.push(root);
        while(!q.empty()){
        	// 节点出队
            TreeNode* temp = q.front();
            q.pop();
            // 将出队的节点放入容器
            res.push_back(temp->val);
            // 将左右孩子分别入队即可
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return res;
    }
};