## [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)

### 题目描述

难度简单

给定一个仅包含大小写字母和空格 `' '` 的字符串 `s`，返回其最后一个单词的长度。

如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

**说明：**一个单词是指仅由字母组成、不包含任何空格的 **最大子字符串**。

 

**示例:**

```
输入: "Hello World"
输出: 5
```

通过

### 分析

题目分析

### 解法一

我的第二个解答：应用字符串方法

```c++
//0ms, 8.9MB
class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty() && s.back() == ' ') s.pop_back();
        if(s.empty())   return 0;
        else return s.length()-1-s.find_last_of(' ');
    }
};
```

leetcode解答区的解答

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int pos=s.find_last_of(' ');//寻找到最后一个空格
        while(pos==s.length()-1)//将末尾的空格全部删除
        {
            if(s.empty()) return 0;
            s.erase(pos);
            pos=s.find_last_of(' ');
        }
        return s.length()-pos-1;
    }
};
```

### 解法二

我的解答：

先排除最右侧的所有空格，再从右向左找出第一个空格

```c++
//8ms, 8.8MB
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i;
        while(n!=0 && s[n-1] == ' ')    n--;
        for(i=0;i<n;i++) {
            if(s[n-i-1] == ' ')   break;
        }
        return i;
    }
};
```

