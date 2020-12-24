## [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

### 题目描述

难度中等

给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

### 分析

题目分析

#### 题解1：brute force

遍历所有的子串

```python
#sol1
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        for j in range(len(s)+1):
            for i in range(j):
                #[i,j)为遍历所有的子串
                _set=set()
                for k in range(i,j):
                    if s[k] in _set:
                        res=max(res,k-i)
                        break
                    else:
                        res=max(res,k-i+1)
                        _set.add(s[k])
        return res
```



#### 题解2：brute force

题解1的优化，遍历所有的字符，找出以当前字符为子串首字符的最大子串

```python
#sol2
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            #考虑以s[i]开头的子串，找出最长符合要求的子串
            _set = set()
            for j in range(i,len(s)):
                if(s[j] not in _set):
                    _set.add(s[j])
                    if(j == len(s)-1): #最大的子串延续到串尾的情况
                        res = max(res,len(s)-i)
                else:
                    res = max(res,j - i)
                    break
        return res
```



#### 题解3：活动窗口

要求：window从i到j全部符合要求；移动右边端点，需要在$O(1)$时间内确定

因为窗口内的元素都是没有重复的，如果重复，新窗口的头部，就是重复节点的下一个字符

- 使用一个hashtable来保存每个字符最后出现的位置

注意：

1. 在判断s[i]在Hashtable中之后，需要判断hashtable[s[i]]是否在当前窗口中，若不在，则不需要更改窗口起始位置

```python
#sol3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        end = 0
        res = 0
        hashtable = {}
        for i in range(len(s)):
            end = i
            if s[i] in hashtable:
                start = hashtable[s[i]] + 1
                hashtable[s[i]] = i
            else:
                hashtable[s[i]] = i
            res = max(res, end -start + 1)
        return res
```















