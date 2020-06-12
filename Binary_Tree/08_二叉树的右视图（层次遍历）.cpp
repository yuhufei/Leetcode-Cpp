
// ====================================
// 二叉树的右视图  leetcode 199
// ====================================
// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 结果容器
        vector<int> res;
        if (!root) return res;
        // 构建队列
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            // 队列中最后一个入队的元素加入结果中，因为每次入队都是从左到右，所以最后一个就是最右边的节点
            res.push_back(q.back()->val);

            for (int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                // 左右孩子入队
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

        }
        return res;
    }
};