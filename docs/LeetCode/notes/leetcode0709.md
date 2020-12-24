## [709. 转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/)

### 题目描述

难度简单

实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

**示例 1：**

```
输入: "Hello"
输出: "hello"
```

**示例 2：**

```
输入: "here"
输出: "here"
```

**示例** **3：**

```
输入: "LOVELY"
输出: "lovely"
```

### 分析

根据ASCII值求解

A：65

a：97

### 解法一

解法一说明

```c++
class Solution {
public:
    string toLowerCase(string str) {
        for(char& c : str){
            if('A'<=c && c<='Z') c+=32;
        }
        return str;
    }
};
```

### 解法二

解法二说明

```c++

```

