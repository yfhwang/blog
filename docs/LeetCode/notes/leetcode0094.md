## [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) 

## [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

## [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

### 题目描述

给定一个二叉树，返回它的前、中、后序遍历。

 **示例:**

```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

前序输出: [1,2,3]
中序输出: [1,3,2]
后序输出: [3,2,1]
```

### 解法一

递归

```c++
//中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int> &ans){
        while(!root) return;
        if(root->left){
            inorder(root->left,ans);
        }
        ans.push_back(root->val);
        if(root->right){
            inorder(root->right,ans);
        }
    }
};
```

### 解法二

迭代

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;//st用来存放节点
        TreeNode *p=root;	//p表示当前节点
        while(!st.empty() || p){
            while(p){
                ans.push_back(p->val);
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            p=p->right;
        }
        return ans;
    }
    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {	
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;//st用来存放节点
        TreeNode *p=root;	//p表示当前节点
        while(!st.empty() || p){
            while(p){
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            ans.push_back(p->val);
            p=p->right;
        }
        return ans;
    }
    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {	
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while(!st.empty() || p){
            while(p){   //将p的左子树入栈
                st.push(p);
                p=p->left;
            }
            p=st.top(); //取栈顶元素
            if(!p->right || p->right == pre){   //若p无右子树，或右子树已被访问过
                st.pop();
                ans.push_back(p->val);  //访问右子树
                pre = p;
                p = NULL;
            }else{
                p=p->right;
            }
        }
        return ans;
    }
};
```

