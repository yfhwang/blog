## [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)

### 题目描述

难度简单

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

**示例 1:**

```
输入: 123
输出: 321
```

 **示例 2:**

```
输入: -123
输出: -321
```

**示例 3:**

```
输入: 120
输出: 21
```

**注意:**

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为$[−2^{31}, 2^{31} − 1]$。请根据这个假设，如果反转后整数溢出那么就返回 0。



### 分析

题目分析

### 解法一

解法一说明

```python
#sol1
class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2 ** 31 - 1
        INT_MIN = - 2 ** 31
        if(x == INT_MIN):
            return 0
        sign = True if x >= 0 else False
        rev = 0
        if(x < 0):
            x = -x
        while(x != 0):
            pop = x % 10
            x = x // 10
            if(rev > INT_MAX // 10 or (rev == INT_MAX // 10 and pop > 7)):
                return 0
            rev = rev * 10 + pop
        
        return rev if sign else -1 * rev
```

### 解法二

解法二说明

```python

```

