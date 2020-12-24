## [429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)

### 题目描述

难度中等

给定一个 N 叉树，返回其节点值的*层序遍历*。 (即从左到右，逐层遍历)。

例如，给定一个 `3叉树` :

![img](../images/narytreeexample.png)

返回其层序遍历:

```
[
     [1],
     [3,2,4],
     [5,6]
] 
```

**说明:**

1. 树的深度不会超过 `1000`。
2. 树的节点总数不会超过 `5000`。

### 分析

题目分析

### 解法一

dfs 递归 recursivve

```c++
// Author: Huahua
// Running time: 44 ms
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    preorder(root, 0, ans);
    return ans;
  }
private:
  void preorder(Node* root, int d, vector<vector<int>>& ans) {
    if (root == nullptr) return;
    while (ans.size() <= d) ans.push_back({});
    ans[d].push_back(root->val);
    for (auto child : root->children)
      preorder(child, d + 1, ans);
  }
};
```

### 解法二

bfs 迭代 iterative

```c++
// Author: Huahua
// Running time: 44 ms
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> ans;    
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
      int size = q.size();
      ans.push_back({});
      while (size--) {
        Node* n = q.front(); q.pop();
        ans.back().push_back(n->val);
        for (auto child : n->children)
          q.push(child);
      }
      ++height;
    }
    return ans;
  }
};
```

