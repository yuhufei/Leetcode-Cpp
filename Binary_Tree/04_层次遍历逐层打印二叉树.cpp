// ====================================
// 从上到下逐层打印二叉树  Leetcode 32-II
// ====================================

// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
// 如输入二叉树[1， 2， 3]  返回[[1], [2, 3]]因为根节点在第一层，2， 3都在第二层


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	// 二维容器用于保存结果
        vector<vector<int>> res;
        if(root == NULL) return res;
        // 定义一个队列
        queue<TreeNode*> q;
        // 将根节点入队
        q.push(root);

        while(!q.empty()){
        	// 记录队列中的元素个数
            int n = q.size();
            // 用于保存每层元素的容器
            vector<int> level;
            // 对于每一层使用for循环逐个出队，并加入层容器中，每执行for循环一次就会完成一层的遍历
            // 图的广度优先搜索也是这样，希望能熟练掌握。
            for(int i = 0; i < n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            // 将层容器加入到结果容器中
            res.push_back(level);
        }
        return res;
    }
};