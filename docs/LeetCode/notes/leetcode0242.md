## [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

### 题目描述

难度简单

给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的字母异位词。

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

**说明:**
你可以假设字符串只包含小写字母。

**进阶:**
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

### 分析

题目分析

### 解法一

解法一说明

```c++
//8ms, 9.6MB
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[123]={0};
        for(char& c : s)
            hash[c]++;
        for(char&c : t)
            hash[c]--;
        for(int i=97;i<123;i++)
            if(hash[i]!=0)  return false;
        return true;
    }
};
```

### 解法二

解法二说明

```c++

```

