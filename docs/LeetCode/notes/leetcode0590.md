## [590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)

### 题目描述

难度简单

给定一个 N 叉树，返回其节点值的*后序遍历*。

例如，给定一个 `3叉树` :

![img](../images/narytreeexample-20200223203624998.png) 

返回其后序遍历: `[5,6,3,2,4,1]`.

**说明:** 递归法很简单，你可以使用迭代法完成此题吗?

### 分析

题目分析

### 解法一

recursive递归

```c++
// Author: Huahua
// Running time: 44 ms
class Solution {
public:
  vector<int> postorder(Node* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
  }
private:
  void postorder(Node* root, vector<int>& ans) {
    if (!root) return;
    for (auto child : root->children)
      postorder(child, ans);
    ans.push_back(root->val);
  }
};
```

### 解法二

iterative迭代

- 巧妙：中右左的顺序遍历，之后反转

```c++
// Author: Huahua
// Running time: 44 ms
class Solution {
public:
  vector<int> postorder(Node* root) {
   if (!root) return {};
    vector<int> ans;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      const Node* node = s.top(); s.pop();      
      ans.push_back(node->val);
      for (auto child : node->children)
        s.push(child);      
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};
```

