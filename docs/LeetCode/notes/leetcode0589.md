## [589. N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)

### 题目描述

难度简单

给定一个 N 叉树，返回其节点值的*前序遍历*。

例如，给定一个 `3叉树` :

 

![img](../images/narytreeexample-20200223201905952.png)

 

返回其前序遍历: `[1,3,5,6,2,4]`。

**说明:** 递归法很简单，你可以使用迭代法完成此题吗?

### 分析

题目分析

### 解法一

递归 recursive

```c++
// Author: Huahua
// Running time: 48 ms
class Solution {
public:
  vector<int> preorder(Node* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }
private:
  void preorder(Node* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    for (const auto& child : root->children)
      preorder(child, ans);
  }
};
```

### 解法二

迭代 iterative

- 使用反向迭代器，在`stack`中逆序插入某个元素的所有孩子节点

```c++
// Author: Huahua
// Running time: 52 ms
class Solution {
public:
  vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> ans;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      const Node* node = s.top(); s.pop();
      ans.push_back(node->val);
      for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
        s.push(*it);
    }
    return ans;
  }
};
```

