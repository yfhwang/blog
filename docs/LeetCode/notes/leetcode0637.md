## [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/)

### 题目描述

难度简单

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

**示例 1:**

```
输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
```

**注意：**

1. 节点值的范围在32位有符号整数范围内。

### 分析

类似102题，可用levelorder的方法做

### 解法一

BFS

```c++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)   return {};
        vector<double> ans;
        vector<TreeNode*> curr,next;
        curr.push_back(root);
        while(!curr.empty()){
            long sum=0;
            for(const auto& p : curr){
                sum += p->val;
                if(p->left) next.push_back(p->left);
                if(p->right) next.push_back(p->right);
            }
            ans.push_back((double)sum/curr.size());
            swap(curr,next);
            next.clear();
        }
        return ans;
    }
};
```

### 解法二

DFS

- pair的使用
- auto的使用

```c++
// Author: Huahua
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        vector<pair<long long, int>> sum_count;
        vector<double> ans;
        preorder(root, 0, sum_count);
        for(const auto& p : sum_count)
            ans.push_back(static_cast<double>(p.first) / p.second);
        return ans;
    }
    
private:
    void preorder(TreeNode* root, int height, vector<pair<long long, int>>& sum_count) {
        if(root == nullptr) return;
        if(height>=sum_count.size()) sum_count.push_back({0,0});
        sum_count[height].first += root->val;
        ++sum_count[height].second;
        preorder(root->left, height+1, sum_count);
        preorder(root->right, height+1, sum_count);
    }
};
```

