// ======================================
// 从上到下逐层打印二叉树
// 偶数层倒序，Leetcode 32-III
// ======================================

// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行，且偶数层倒序。
// 如输入二叉树[1， 2， 3]  返回[[1], [3, 2]]因为根节点在第一层，2， 3都在第二层要倒序

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	// 保存结果的容器
        vector<vector<int>> res; 
        // 构建一个队列
        queue<TreeNode*> q;
        // 记录树的高度
        int deep = 0;
        if(root==NULL) return res;
        // 根节点入队
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            // 保存层结果
            vector<int> level;
            // for循环每执行一轮，就完成一层的遍历
            for(int i = 0; i < n; i++){
                TreeNode * tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            // 层数加1
            deep++;
            // 偶数层，层结果倒序
            if(deep % 2 == 0) reverse(level.begin(), level.end());
            // 将层结果加入到结果容器中
            res.push_back(level);
        }
        return res;
    }
};

