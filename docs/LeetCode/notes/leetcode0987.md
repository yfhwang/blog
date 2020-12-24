## [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/)

### 题目描述

难度中等

给定二叉树，按*垂序*遍历返回其结点值。

对位于 `(X, Y)` 的每个结点而言，其左右子结点分别位于 `(X-1, Y-1)` 和 `(X+1, Y-1)`。

把一条垂线从 `X = -infinity` 移动到 `X = +infinity` ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ `Y` 坐标递减）。

如果两个结点位置相同，则首先报告的结点值较小。

按 `X` 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。

**示例 1：**

![img](../images/1236_example_1.PNG)

```
输入：[3,9,20,null,null,15,7]
输出：[[9],[3,15],[20],[7]]
解释： 
在不丧失其普遍性的情况下，我们可以假设根结点位于 (0, 0)：
然后，值为 9 的结点出现在 (-1, -1)；
值为 3 和 15 的两个结点分别出现在 (0, 0) 和 (0, -2)；
值为 20 的结点出现在 (1, -1)；
值为 7 的结点出现在 (2, -2)。
```

**示例 2：**

**![img](../images/tree2.png)**

```
输入：[1,2,3,4,5,6,7]
输出：[[4],[2],[1,5,6],[3],[7]]
解释：
根据给定的方案，值为 5 和 6 的两个结点出现在同一位置。
然而，在报告 "[1,5,6]" 中，结点值 5 排在前面，因为 5 小于 6。
```

**提示：**

1. 树的结点数介于 `1` 和 `1000` 之间。
2. 每个结点值介于 `0` 和 `1000` 之间。

### 分析

题目分析

### 解法一

解法一说明

```c++
// Author: Huahua, running time: 0 ms, 921.6 KB 
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    map<pair<int, int>, set<int>> h; // {y, x} -> {vals}
    traverse(root, 0, 0, h, min_x, max_x);
    vector<vector<int>> ans(max_x - min_x + 1);
    for (const auto& m : h) {      
      int x = m.first.second - min_x;
      ans[x].insert(end(ans[x]), begin(m.second), end(m.second));
    }
    return ans;
  }
private:
  void traverse(TreeNode* root, int x, int y, 
                map<pair<int, int>, set<int>>& h,
                int& min_x,
                int& max_x) {
    if (!root) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);    
    h[{y, x}].insert(root->val);
    traverse(root->left, x - 1, y + 1, h, min_x, max_x);
    traverse(root->right, x + 1, y + 1, h, min_x, max_x);
  }
};
```

### 解法二

解法二说明

```c++

```

