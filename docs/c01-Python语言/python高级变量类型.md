### 高级变量类型

#### **列表**

```python
name_list = ["zhangsan", "lisi", "wangwu"]
print list[1:3]          # 输出第二个至第三个元素 
```



| 序号 | 分类 | 关键字 / 函数 / 方法    | 说明                     |
| ---- | ---- | ----------------------- | ------------------------ |
| 1    | 增加 | 列表.insert(索引, 数据) | 在指定位置插入数据       |
|      |      | 列表.append(数据)       | 在末尾追加数据           |
|      |      | 列表.extend(列表2)      | 将列表2 的数据追加到列表 |
|      |      |                         |                          |
| 3    | 删除 | 列表.remove[数据]       | 删除第一个出现的指定数据 |
|      |      | 列表.pop                | 删除末尾数据             |
|      |      | 列表.pop(索引)          | 删除指定索引数据         |
|      |      | 列表.clear              | 清空列表                 |
|      |      |                         |                          |
| 4    | 统计 | len(列表)               | 列表长度                 |
|      |      | 列表.count(数据)        | 数据在列表中出现的次数   |
|      |      |                         |                          |
| 5    | 排序 | 列表.sort()             | 升序排序                 |
|      |      | 列表.sort(reverse=True) | 降序排序                 |
|      |      | 列表.reverse()          | 逆序、反转               |



#### **元组**

`Tuple`（元组）与列表类似，不同之处在于元组的 **元素不能修改**

```python
info_tuple = ("zhangsan", 18, 1.75)
```



| 关键字 / 函数 / 方法   | 说明   |
| ---------------------- | ------ |
| info.index("zhangsan") | 查索引 |



#### 字典

和列表的区别

* **列表** 是 **有序** 的对象集合
* **字典** 是 **无序** 的对象集合

```python
xiaoming = {"name": "小明",
            "age": 18,
            "gender": True,
            "height": 1.75}

dict = {}
dict['one'] = "This is one"
dict[2] = "This is two"
```



| 关键字 / 函数 / 方法 | 说明       |
| -------------------- | ---------- |
| xiaoming.keys        | 输出所有键 |
| xiaoming.values      | 输出所有值 |



#### 字符串

```python
string = "Hello Python"

for c in string:
    print(c)
```

| 方法                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [string.capitalize()](https://www.runoob.com/python/att-string-capitalize.html) | 把字符串的第一个字符大写                                     |
| **[string.count(str, beg=0, end=len(string))](https://www.runoob.com/python/att-string-count.html)** | 返回 str 在 string 里面出现的次数，如果 beg 或者 end 指定则返回指定范围内 str 出现的次数 |
| **[string.endswith(obj, beg=0, end=len(string))](https://www.runoob.com/python/att-string-endswith.html)** | 检查字符串是否以 obj 结束，如果beg 或者 end 指定则检查指定的范围内是否以 obj 结束，如果是，返回 True,否则返回 False. |
| **[string.find(str, beg=0, end=len(string))](https://www.runoob.com/python/att-string-find.html)** | 检测 str 是否包含在 string 中，如果 beg 和 end 指定范围，则检查是否包含在指定范围内，如果是返回开始的索引值，否则返回-1 |
| **[string.index(str, beg=0, end=len(string))](https://www.runoob.com/python/att-string-index.html)** | 跟find()方法一样，只不过如果str不在 string中会报一个异常.    |
| **[string.format()](https://www.runoob.com/python/att-string-format.html)** | 格式化字符串                                                 |
| **[string.join(seq)](https://www.runoob.com/python/att-string-join.html)** | 以 string 作为分隔符，将 seq 中所有的元素(的字符串表示)合并为一个新的字符串 |
| **[string.replace(str1, str2, num=string.count(str1))](https://www.runoob.com/python/att-string-replace.html)** | 把 string 中的 str1 替换成 str2,如果 num 指定，则替换不超过 num 次. |
| **[string.split(str="", num=string.count(str))](https://www.runoob.com/python/att-string-split.html)** | 以 str 为分隔符切片 string，如果 num 有指定值，则仅分隔 num+ 个子字符串 |



#### 公共方法

| 函数              | 描述                              | 备注                        |
| ----------------- | --------------------------------- | --------------------------- |
| len(item)         | 计算容器中元素个数                |                             |
| del(item)         | 删除变量                          | del 有两种方式              |
| max(item)         | 返回容器中元素最大值              | 如果是字典，只针对 key 比较 |
| min(item)         | 返回容器中元素最小值              | 如果是字典，只针对 key 比较 |
| cmp(item1, item2) | 比较两个值，-1 小于/0 相等/1 大于 | Python 3.x 取消了 cmp 函数  |

**切片**

| 描述 | Python 表达式      | 结果    | 支持的数据类型     |
| :--: | ------------------ | ------- | ------------------ |
| 切片 | "0123456789"[::-2] | "97531" | 字符串、列表、元组 |

**运算符**

|    运算符    | Python 表达式         | 结果                         | 描述           | 支持的数据类型           |
| :----------: | --------------------- | ---------------------------- | -------------- | ------------------------ |
|      +       | [1, 2] + [3, 4]       | [1, 2, 3, 4]                 | 合并           | 字符串、列表、元组       |
|      *       | ["Hi!"] * 4           | ['Hi!', 'Hi!', 'Hi!', 'Hi!'] | 重复           | 字符串、列表、元组       |
|      in      | 3 in (1, 2, 3)        | True                         | 元素是否存在   | 字符串、列表、元组、字典 |
|    not in    | 4 not in (1, 2, 3)    | True                         | 元素是否不存在 | 字符串、列表、元组、字典 |
| > >= == < <= | (1, 2, 3) < (2, 2, 3) | True                         | 元素比较       | 字符串、列表、元组       |



 **for 循环语法**

* 在 `Python` 中完整的 `for 循环` 的语法如下：

```python
for 变量 in 集合:
    
    循环体代码
else:
    没有通过 break 退出循环，循环结束后，会执行的代码
```





