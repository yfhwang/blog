## [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

### 题目描述

难度中等

给定一个二叉树，返回它的 *前序* 遍历。

 **示例:**

```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
```

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

### 分析

题目分析

### 解法一

Recursion递归

Time complexity: O(n)
Space complexity: O(n)

- 花花的源代码使用了C++11中的匿名函数(lambda函数,lambda表达式)，我将其改成了preorder函数

```c++
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;    
    preorder(root,ans);
    return ans;
  }
private:
    void preorder(TreeNode* n, vector<int>& ans){
      if (!n) return;
      ans.push_back(n->val);
      preorder(n->left,ans);
      preorder(n->right,ans);
    }
};
```

### 解法二

Stack迭代

Time complexity: O(n)
Space complexity: O(n)

- 和天勤的版本相比，没有当前节点p，使代码更加简洁
- 但天勤的可以很好地统一前、中、后序遍历；这种方法只能统一前、后序遍历
- 由于stack是先进后出，所有在压栈时要先压右子树，再压左子树

```c++
// Author: Huahua
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> s;
    if (root) s.push(root);
    while (!s.empty()) {
      TreeNode* n = s.top();
      s.pop();
      ans.push_back(n->val);
      if (n->right) s.push(n->right);
      if (n->left) s.push(n->left);            
    }
    return ans;
  }
```

