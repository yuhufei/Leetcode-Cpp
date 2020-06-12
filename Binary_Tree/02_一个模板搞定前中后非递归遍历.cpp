// 二叉树的递归遍历很简单，但是面试的时候面试官为了考查应聘者的深层能力
// 会要求面试者写出非递归遍历的代码。

// 学习数据结构的过程中我们都会感觉非递归遍历十分复杂，各种边界条件都要考虑
// 这里提供一套可以解决前中后非递归遍历的简单代码，只需要改动几行代码就可以实现
// 前序和后序遍历 ----思路来自leetcode上PualKing

// ===========================
// 1. 前序遍历，leetcode 144题
// ===========================

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	// 用于保存结果的容器
        vector<int> res;  
        // 构建一个栈保存入栈的临时节点
        stack<TreeNode*> sta;  
        // 将跟节点入栈
        if(root!=nullptr) sta.push(root); 

        while(!sta.empty()){
        	// 节点出栈
            TreeNode *tmp = sta.top();
            sta.pop();  
            if(tmp!=nullptr){
            	// 注意这里：前序遍历的顺序是根节点、左孩子、右孩子，而栈先进后出
            	// 故入栈顺序后、左、根
            	// 中序和后序也只需要改这里的入栈顺序即可
                if(tmp->right) sta.push(tmp->right);  
                if(tmp->left) sta.push(tmp->left);
                // 根节点入栈，标记为nullptr
                sta.push(tmp);  
                sta.push(nullptr);  
            }
            else  //如果出栈的是空指针，表示访问过了，直接加入结果
            {  
                res.push_back(sta.top()->val);                         
                sta.pop();  
            }
        }
        return res;
    }
};


// ===========================
// 2. 中序遍历，leetcode 94题
// =========================== 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        if(root) sta.push(root);
        while(!sta.empty()){
            TreeNode * tmp = sta.top();
            sta.pop();
            if(tmp!=nullptr){
            	// 与前序遍历相比仅仅改变了这里的入栈顺序
                if(tmp->right) sta.push(tmp->right);
                sta.push(tmp);
                sta.push(nullptr);
                if(tmp->left) sta.push(tmp->left);
            }else{
                res.push_back(sta.top()->val);
                sta.pop();
            }
        }
        return res;
    }
};




// ===========================
// 3. 后序遍历，leetcode 145题
// =========================== 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        if(root) sta.push(root);
        while(!sta.empty()){
            TreeNode * tmp = sta.top();
            sta.pop();
            if(tmp!=nullptr){
            	// 与前序遍历相比仅仅改变了这里的入栈顺序
                sta.push(tmp);
                sta.push(nullptr);
                if(tmp->right) sta.push(tmp->right);
                if(tmp->left) sta.push(tmp->left);
            }else{
                res.push_back(sta.top()->val);
                sta.pop();
            }
        }
        return res;  
    }
};
