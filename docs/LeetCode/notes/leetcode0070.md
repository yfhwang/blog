## [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

难度简单

### 题目描述

假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**注意：**给定 *n* 是一个正整数。

**示例 1：**

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

**示例 2：**

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```

### 分析

f[i] = f[i-1] + f[i-2]

state:	[ i ]

init:	[0] = 1, [1] = 1

func:  curr = curr + prev

res:

### 解法一

存储下所有阶层的方法

```c++
// Author: Huahua
// Running time: 0 ms
class Solution {
public:
  int climbStairs(int n) {
    vector<int> f(n + 1, 0);
    f[0] = f[1] = 1;
    for (int i = 2;i <= n; ++i)
      f[i] = f[i - 1] + f[i - 2];
    return f[n];
  }
};
```

### 解法二

不存储所有的阶层，只存储当前阶和前两阶

```c++
// Author: Huahua
// Running time: 0 ms
class Solution {
public:
  int climbStairs(int n) {
    int two = 1;
    int one = 1;
    int curr = 1;
    // curr = two + one
    for (int i = 2; i <= n; ++i) {
        curr = two + one;
        two = one;
        one = curr;
    }
    return curr;
  }
};
```

