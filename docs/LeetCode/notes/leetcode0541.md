## [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

### 题目描述

难度简单

给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

**示例:**

```
输入: s = "abcdefg", k = 2
输出: "bacdfeg"
```

**要求:**

1. 该字符串只包含小写的英文字母。
2. 给定字符串的长度和 k 在[1, 10000]范围内。

### 分析

题目分析

### 解法一

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        int n = size / (2 * k);
        int remainder = size% (2*k) ;
        for(int t=0; t < n; t++)
            reverse(s.begin()+t*2*k,s.begin()+(t*2+1)*k);
        if(remainder>=k)
            reverse(s.begin()+n*2*k,s.begin()+(n*2+1)*k);
        else if(remainder>1)
            reverse(s.begin()+n*2*k,s.end());
        return s;
    }
};
```

### 解法二

解法二说明

```c++

```

