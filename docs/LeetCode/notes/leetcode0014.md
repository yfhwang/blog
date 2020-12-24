## [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

### 题目描述

难度简单

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

**示例 1:**

```
输入: ["flower","flow","flight"]
输出: "fl"
```

**示例 2:**

```
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```

**说明:**

所有输入只包含小写字母 `a-z` 。

### 分析

题目分析

### 解法一

我的解法：从第一个字符串开始，与后面每一个字符串的前缀比较

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())  return "";
        string common = strs.front();
        int size = strs.size();

        for(int i=1;i<size;i++){
            int common_size = common.size()<strs[i].size()?
                    common.size():strs[i].size();
            if(!common_size)    return "";
            int j=0;
            for(j=0;j<common_size;j++){
                if(common[j]!=strs[i][j])   break;
            }
            common.erase(common.begin()+j,common.end());
        }
        return common;
    }
};
```

### 解法二

九章：从第一个字符开始，直到最后一个匹配的字符

```c++
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }
        
        return prefix;
    }
};
```

