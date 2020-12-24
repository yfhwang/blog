## [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/)

### 题目描述

难度简单

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

**示例 1:**

```
输入: 121
输出: true
```

**示例 2:**

```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

**示例 3:**

```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```

**进阶:**

你能不将整数转为字符串来解决这个问题吗？

### 分析

题目分析

### 解法1

将数字后半段反转，然后判断是否相等

1. 判断x<0 或 x为非0且以0结尾
2. 反转x的后半段，判断是否相等

注意：

- 需要考虑x为奇数位的情况

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x < 0 or (x > 0 and x % 10 == 0)):
            return False
        rev_x = 0
        while(x > rev_x):
            pop = x % 10
            x = x // 10
            rev_x = rev_x * 10 + pop
        return x == rev_x or x == rev_x // 10
```

### 解法二

解法二说明

```python

```

