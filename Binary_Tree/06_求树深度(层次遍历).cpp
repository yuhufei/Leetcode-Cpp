// ====================================
// 二叉树的最大深度  Leetcode 104题
// ====================================

// 曾经在网上见到有人面试阿里巴巴遇到这题，轻松的写出了递归代码，
// 但是面试官要求写非递归，面试者就直接傻眼了，面试结果自然没通过。
// 其实可以用层次遍历解决，几乎还是上面几题层次遍历的模板。


// 递归方法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

// 非递归方法--->层次遍历，上面连着两题都是层次遍历，其实可以直接求出上面结果的size()，就是树的深度，但是
// 太浪费空间了，还记得上面说的每轮for循环都是一个完成一层的遍历的吗，因此可以在for循环后直接记录结果。

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	// 定义一个遍历保存树的深度
        int deep = 0;
        if(!root) return deep;
        // 还是定义一个队列
        queue<TreeNode*> q;
        // 将根节点入队
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            // 每轮for循环都是执行完一层遍历
            for(int i = 0; i < n; i++){
                TreeNode* tmp = q.front();
                q.pop(); 
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            // 深度加1
            deep++;
        }
        return deep;
    }
};