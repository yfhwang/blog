## [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)

### 题目描述

难度中等

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

自顶向下的最小路径和为 `11`（即，**2** + **3** + **5** + **1** = 11）。

**说明：**

如果你可以只使用 *O*(*n*) 的额外空间（*n* 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

### 分析

题目分析

### 解法一

解法一说明

```c++
// Author: Huahua
// Running time: 4 ms
class Solution {
public:
  // [[2]                 [[2]
  //  [3, 4]]              [5, 6]
  //  [6, 5, 7]]           [11, 10, 11]
  //  [4, 1, 8, 3]]        [15, 11, 18, 14]]
  int minimumTotal(vector<vector<int>>& t) {
    int n = t.size();        
 
    // t[i][j] := minTotalOf(i,j)
    // t[i][j] += min(t[i - 1][j], t[i - 1][j - 1])
 
    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j) {
        if (i == 0 && j == 0) continue;
        if (j == 0) t[i][j] += t[i - 1][j];
        else if (j == i) t[i][j] += t[i - 1][j - 1];
        else t[i][j] += min(t[i - 1][j], t[i - 1][j - 1]);
      }
 
    return *std::min_element(begin(t.back()), end(t.back()));
  }
};
```

改进解法一

```c++
//0ms
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto& t = triangle;
        int n = t.size();
        if(n==0)    return 0;
        for(int i=1;i<n;i++) {
            t[i][0]+=t[i-1][0];
            t[i][i]+=t[i-1][i-1];
            for(int j=1;j<i;j++) {
                t[i][j]+=min(t[i-1][j-1],t[i-1][j]);
            }
        }
        return *min_element(t.back().begin(),t.back().end());
    }
};
```





### 解法二

定义一个数组，最简单的方式

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j) {
                f[i][j] = triangle[i - 1][j - 1];
                if (i == 1 && j == 1)	continue;
                if (j == 1)	f[i][j] += f[i - 1][j];
                else if (j == i) f[i][j] += f[i - 1][j - 1];
                else	f[i][j] += min(f[i - 1][j], f[i - 1][j - 1]);
            }
        return *min_element(f[n].cbegin(), f[n].cend());
    }
};
```

