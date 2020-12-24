## [150. 逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

### 题目描述

难度中等

根据[逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437)，求表达式的值。

有效的运算符包括 `+`, `-`, `*`, `/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

**说明：**

- 整数除法只保留整数部分。
- 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

**示例 1：**

```
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
```

**示例 2：**

```
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
```

**示例 3：**

```
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```



### 分析

逆波兰表达式（后缀表达式）求值：

- 依次扫描表达式的值，若为数字，则入栈；
- 若为运算符，则取出栈顶的两个数字计算后再次入栈

### 解法一



```c++
//16ms
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) return 0;
        int a, b, a_op_b;
        stack<int> st;
        for (auto &s : tokens) {
            if (s[0] == '-' && s.size() != 1) { //当前为负数
                int temp = 0;
                int size = s.size();
                for (int i = 1; i < size; i++) {
                    temp = temp * 10 + s[i] - '0';
                }
                st.push(-1 * temp);
            } else if (s[0] >= '0' && s[0] <= '9') {    //为正数
                int temp = 0;
                int size = s.size();
                for (int i = 0; i < size; i++) {
                    temp = temp * 10 + s[i] - '0';
                }
                st.push(temp);
            } else {    //为符号
                b = st.top();   //先取出的为运算中的第二个数
                st.pop();
                a = st.top();   //后取出的才是第一个数
                st.pop();
                a_op_b = op(a, s[0], b);
                st.push(a_op_b);
            }
        }
        return st.top();
    }

private:
    static int op(int a, char c, int b) {
        if (c == '+')
            return a + b;
        else if (c == '-')
            return a - b;
        else if (c == '*')
            return a * b;
        else
            return a / b;
    }
};
```

### 解法二

解法二说明

```c++

```

