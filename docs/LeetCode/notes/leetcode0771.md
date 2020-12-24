## [771. 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)

### 题目描述

难度简单

 给定字符串`J` 代表石头中宝石的类型，和字符串 `S`代表你拥有的石头。 `S` 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

`J` 中的字母不重复，`J` 和 `S`中的所有字符都是字母。字母区分大小写，因此`"a"`和`"A"`是不同类型的石头。

**示例 1:**

```
输入: J = "aA", S = "aAAbbbb"
输出: 3
```

**示例 2:**

```
输入: J = "z", S = "ZZ"
输出: 0
```

**注意:**

- `S` 和 `J` 最多含有50个字母。
-  `J` 中的字符不重复。

### 分析

题目分析

### 解法一

我的题解：12ms, 9MB

```c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hash;
        int res = 0;
        for(const char& j : J)  hash.insert(j);
        for(const char& s : S) 
            if(hash.count(s))   res++;
        return res;
    }
};
```

### 解法二

解法二说明

```c++

```

