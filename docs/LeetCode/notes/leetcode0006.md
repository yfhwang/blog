## [6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)

### 题目描述

难度中等

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"LEETCODEISHIRING"` 行数为 3 时，排列如下：

```
L   C   I   R
E T O E S I I G
E   D   H   N
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"LCIRETOESIIGEDHN"`。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```

**示例 1:**

```
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
```

**示例 2:**

```
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```

### 分析

给出行数，把一个字符串转化为一个从左到右的Z字型，然后再按正常顺序输出该字符串。

### 方法1：按行排序

1. 初始化一个字符数组，字符数组的维数为len(s)和numRows的较小值
2. 定义布尔型goingDown来表示，当前字符在字符数组中，相对上一个字符，应该向下还是向上
3. 使用curRow来表示当前字符在字符数组中的位置
4. 按字符遍历字符串，依次添加到字符数组中

```python
#sol1
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s
        #初始化字符数组、当前字符所在行、当前字符相对上一个字符的位置
        dim = numRows if numRows < len(s) else len(s)
        rows = [[] for j in range(dim)]
        curRow = 0
        goingDown = False
        
        #按字符遍历字符串
        for c in s:
            rows[curRow].append(c)
            if(curRow == 0 or curRow == numRows - 1):
                goingDown = not goingDown
            curRow = curRow + 1 if goingDown else curRow - 1
        
        #将字符数组重新成字符串
        res = ''
        for row in rows:
            res = res + ''.join(row)
        return res
```

### 解法二

解法二说明

```python

```

