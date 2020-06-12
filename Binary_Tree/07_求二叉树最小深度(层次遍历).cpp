
// ====================================
// 求二叉树的最小深度  leetcode 111
// ====================================
// 树的最小深度指的是从根节点到第一个叶子节点的高度


class Solution {
public:
    int minDepth(TreeNode* root) {
        // 记录高度
        int depth = 0;
        if(!root) return depth;
        // 构建一个队列
        queue<TreeNode*> q;
        // 根节点入队
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            // 层数加1
            depth++;
            // 每轮for循环都完成了一层遍历
            for(int i = 0; i <n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                // 发现第一个叶子节点，直接返回高度
                if(!tmp->left && ! tmp->right){
                    return depth;
                }
                // 左右孩子入队
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return depth;
    }
};