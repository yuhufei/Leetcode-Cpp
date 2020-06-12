// 二叉树的遍历是二叉树操作中最基础也是最重要的操作
// 几乎所有的关于树的操作都是用遍历完成，这里介绍树的前中后遍历形式
// 递归实现前中后遍历不同之处仅仅在于访问节点的顺序不同

// ===========================
// 1. 前序遍历，leetcode 144题
// ===========================

class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};


// ===========================
// 2. 中序遍历，leetcode 94题
// =========================== 

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};



// ===========================
// 3. 后序遍历，leetcode 145题
// =========================== 

class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return res;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};
