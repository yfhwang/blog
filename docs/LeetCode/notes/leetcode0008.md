## [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)

### 题目描述

难度中等

请你来实现一个 `atoi` 函数，使其能将字符串转换成整数。

首先，该函数会根据需要**丢弃无用的开头空格字符**，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为**正或者负号**时，则将该符号与之后面尽可能多的<u>连续数字</u>组合起来，作为该整数的正负号；假如第一个非空字符是**数字**，则直接将其与之后<u>连续的数字字符</u>组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数**不需要进行转换**。

在任何情况下，若函数不能进行有效的转换时，请**返回 0**。

**说明：**

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

**示例 1:**

```
输入: "42"
输出: 42
```

**示例 2:**

```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```

**示例 3:**

```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```

**示例 4:**

```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```

**示例 5:**

```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
```

### 分析

题目分析

### 解法一

我的解法：使用字符串方法

```c++
//0ms, 8.6MB
class Solution {
public:
    int myAtoi(string str) {
        while(!str.empty() && str[0] == ' ')    str.erase(str.begin());
        if(str.empty()) return 0;
        int sign = 1;
        if(str[0]=='+') str.erase(str.begin());
        else if(str[0]=='-') {
            str.erase(str.begin());
            sign = -1;
        }
        long long res=0;
        for(char& c : str)
            if(c>='0' && c<='9')    {
                res=res*10+c-'0';
                if(sign * res>INT_MAX)  return INT_MAX;
                else if(sign * res<INT_MIN)   return INT_MIN;
            }else break;
        return res * sign;
    }
};
```

### 解法二

使用字符流

```c++
class Solution {
public:
    int myAtoi(string str) {
        int digit=0;
        istringstream is(str);
        is>>digit;
        return digit;
    }
};
```

### 解法3：正则

```
^：匹配字符串开头
[\+\-]：代表一个+字符或-字符
?：前面一个字符可有可无
\d：一个数字
+：前面一个字符的一个或多个
\D：一个非数字字符
*：前面一个字符的0个或多个
```

1. 清楚左侧空格字符`str.lstrip()`
2. 匹配正则`re.findall('正则表达式', str)`
3. 转化为int
4. 32为整数范围限制

```python
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        INT_MAX = 2147483647    
        INT_MIN = -2147483648
        str = str.lstrip()      #清除左边多余的空格
        
        #num_re = re.compile(r'^[\+\-]?\d+')   #设置正则规则
        #num = num_re.findall(str)   #查找匹配的内容
        
        num = re.findall('^[+-]?\d+', str)
        
        num = int(*num) #由于返回的是个列表，解包并且转换成整数
        return max(min(num,INT_MAX),INT_MIN)    #返回值
```

