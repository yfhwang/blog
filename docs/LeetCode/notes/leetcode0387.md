## [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

### 题目描述

难度简单

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

**案例:**

```
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
```

 

**注意事项：**您可以假定该字符串只包含小写字母。

### 分析

题目分析

### 解法一



```c++
//140ms, 13.5MB
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        map<char,int> mp;
        for(char& c : s)
            if(mp.count(c)) mp[c]++;
            else mp[c]=1;
        for(int i=0;i<n;i++)
            if(mp.count(s[i]) && mp[s[i]]==1) return i;
        return -1;
    }
};
```

### 解法二

直接用字符对应的ASCII值做hash的索引

```c++
//52ms, 12.9MB
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int hash[256] = {0};
        for (int i = 0; i < n; i++)
            hash[s[i]]++;
        for (int i = 0; i < n; i++)
            if (hash[s[i]] == 1) return i;
        return -1;
    }
};
```

