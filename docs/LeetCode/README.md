#  LeetCode 刷题

## 参考资料

1. leetcode中文官网: https://leetcode-cn.com/problemset/all/

2. 花花酱的频道：[油管链接](https://www.youtube.com/channel/UC5xDNEcvb1vgw3lE21Ack2Q)、[b站链接](https://space.bilibili.com/9880352/channel/index)

   博客：https://zxi.mytechroad.com/blog/

3. 篮子王的频道：[油管链接](https://www.youtube.com/channel/UCE35PnPX7EZi8nHSegjMn6Q)

4. chrome插件：九章算法刷题小助手：[Chrome链接](https://chrome.google.com/webstore/detail/%E4%B9%9D%E7%AB%A0%E5%88%B7%E9%A2%98%E5%B0%8F%E5%8A%A9%E6%89%8B/anljhkoknafhgofbdhoijjojmhhncblo?hl=zh-CN)

5. soulmachine的leetcode题解书：[GitHub链接](https://github.com/soulmachine/leetcode)

6. [《算法笔记》](算法笔记 胡凡.pdf的替身)

7. [STL库笔记](STL库笔记.md)

## 题量统计

数据来源：花花酱LeetCode题目分类 [GoogleDocs链接](https://docs.google.com/spreadsheets/d/1yRCOJ8KysRVkq0O9IlDriT01tC6lzPapmFO4PCmDJQA/edit#gid=126913158)

| 题目类型                                        | 题量       |
| ----------------------------------------------- | ---------- |
| Advanced                                        | 12         |
| [**Search**](#search)+Recursion(递归)           | **32**+4   |
| [**DP**](#dp)+Greedy                            | **77**+1   |
| [**Graph**](#graph)                             | **45**     |
| [**Tree**](#tree)                               | **38**     |
| [Binary Search](#binarySearch)+DAQ+Two Pointers | **19**+2+3 |
| BST                                             | 9          |
| [HashTable](#HashTable)                         | 2          |
| **[List](#list)**                               | **11**     |
| [String](#string)                               | 32         |

共计255题，255/2=123天，255/4=64天，255/5=51天

每周六天：先做标粗体的类型，每天选择一个类型的题目学习

在一个类型下，同一行的题目做的差不多了就可以做下一行

## 分题型

### <a name="search">Search</a>

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日              | 难度 | 解答 |
| ------------------------------------------------------------ | -------------------- | ---------- | -------- |
| [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) | 2-9 | II     | [DFS、BFS](notes/leetcode0017.md) |
| [39. 组合总和](https://leetcode-cn.com/problems/combination-sum/) | 2-9 | II | [BackTrack(DFS)](notes/leetcode0039.md) |
| [40. 组合综合 II](https://leetcode-cn.com/problems/combination-sum-ii/) | 2-16 | III | [39题的修改](notes/leetcode0040.md) |
| [77. 组合](https://leetcode-cn.com/problems/combinations/)   | 2-16 | I | [回溯法](notes/leetcode0077.md) |
| 78                                                           |        |      |                                              |
| 90                                                           |        |      |                                              |
| 216                                                          |        |      |                                              |
|                                                              |        |      |                                              |
| [46. 全排列](https://leetcode-cn.com/problems/permutations/) |                      |            |          |
| [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/) | | | |
| 784 |  |  |  |
| 943 |  |  |  |
| 996 |  |  |  |

### <a name="dp">DP</a>

四要素法: state	init	func	res

| [题目](https://leetcode-cn.com/problemset/all/)              | 代码完成 | 难度 | 解答                                         |
| :----------------------------------------------------------- | -------- | ---- | -------------------------------------------- |
| [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | 2-10     | I    | [DP](notes/leetcode0070.md)                  |
| [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) | 2-10     | 0    |                                              |
| [1137. 第 N 个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number/) | 2-10     | 0    |                                              |
|                                                              |          |      |                                              |
| [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/) | 2-21     | II   | [预处理](notes/leetcode0303.md)              |
| [1218. 最长定差子序列](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/) | 2-21     | III  | [DP+hashtable](notes/leetcode1218.md)        |
|                                                              |          |      |                                              |
| [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | 2-21     | I    | [DP](notes/leetcode0053.md)                  |
| **[121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)** | 2-21     | I    | [以price或gain为状态](notes/leetcode0121.md) |
|                                                              |          |      |                                              |
| [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) | 3-3      | II   | [递归/递推](notes/leetcode0062.md)           |
| [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/) | 3-3      | II   | [记忆化递归](notes/leetcode0063.md)          |
| [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/) | 3-3      | II   | [dp](notes/leetcode0120.md)                  |
| [174. 地下城游戏](https://leetcode-cn.com/problems/dungeon-game/) | 3-3      | III  | [dp](notes/leetcode0174.md)                  |

### <a name="graph">Graph</a>

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                                          |
| ------------------------------------------------------------ | ------ | ---- | --------------------------------------------- |
| [133. 克隆图](https://leetcode-cn.com/problems/clone-graph/) | 2-11   | III  | [深拷贝：先节点后连接](notes/leetcode0133.md) |
| [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) | 2-22   | I    | [深拷贝](notes/leetcode0138.md)               |
|                                                              |        |      |                                               |
| [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) | 2-22   | II   | [dfs无须回溯](notes/leetcode0200.md)          |
| [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/) | 2-22   | III  | [DFS/并查集](notes/leetcode0547.md)           |
| 695                                                          |        |      |                                               |
| 733                                                          |        |      |                                               |
| ...                                                          |        |      |                                               |
|                                                              |        |      |                                               |
| [841. 钥匙和房间](https://leetcode-cn.com/problems/keys-and-rooms/) | 3-6    | I    | [DFS](notes/leetcode0841.md)                  |
| 1202                                                         |        |      |                                               |

### <a name="tree">Tree</a>

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                                         |
| ------------------------------------------------------------ | ------ | ---- | -------------------------------------------- |
| [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) | 2-13   | 0    | [三种遍历天勤书解法](notes/leetcode0094.md)  |
| [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) | 2-23   | I    | [迭代的方法不同](notes/leetcode0144.md)      |
| [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) | 2-23   | I    | [函数式编程](notes/leetcode0145.md)          |
| **[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)** | 2-23   | I    | **[BFS、DFS](notes/leetcode0102.md)**        |
| [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/) | 2-23   | II   | [BFS、DFS](notes/leetcode0637.md) 方法同上题 |
| [429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/) | 2-23   | I    | [递归、迭代](notes/leetcode0429.md) 方法同上 |
| [589. N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/) | 2-23   | I    | [递归、迭代](notes/leetcode0589.md)          |
| [590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/) | 2-23   | II   | [递归、迭代](notes/leetcode0590.md)          |
| [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/) |        |      | [链接](notes/leetcode0987.md)                |
| 1302                                                         |        |      |                                              |
|                                                              |        |      |                                              |
| 100                                                          |        |      |                                              |
| 101                                                          |        |      |                                              |
| 104                                                          |        |      |                                              |
| 110                                                          |        |      |                                              |
| 111                                                          |        |      |                                              |

### <a name="binarySearch">Binary Search</a>

[**basketwang讲解视频**](https://www.youtube.com/watch?v=-5csS6p9RTo&list=PLH8TFsY0qnE0DzwtPzy1UGniij9pA9cqn)

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                                    |
| ------------------------------------------------------------ | ------ | ---- | --------------------------------------- |
| [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/) | 2-14   | I    | [二分法模板](notes/leetcode0035.md)     |
| [34. 在排序数组中查找<br>元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | 2-24   | II   | [两次查找](notes/leetcode0034.md)       |
|                                                              |        |      |                                         |
| [704. 二分查找](https://leetcode-cn.com/problems/binary-search/) | 2-24   | 0    | [模板](notes/leetcode0704.md)           |
| [981. 基于时间的键值存储](https://leetcode-cn.com/problems/time-based-key-value-store/) |        |      | [题目看不懂](notes/leetcode0981.md)     |
|                                                              |        |      |                                         |
| [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | 2-24   | II   | [套704题模板](notes/leetcode0033.md)    |
| [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/) | 2-24   | II   | [上题改写](notes/leetcode0033.md)       |
| [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) | 2-24   | I    | [还可用DAQ](notes/leetcode0153.md)      |
| [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | 2-24   | II   | [和上题类似](notes/leetcode0154.md)     |
| 162                                                          |        |      |                                         |
| 852                                                          |        |      |                                         |
|                                                              |        |      |                                         |
| [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)    | 2-24   | I    | [二分法、牛顿法](notes/leetcode0069.md) |
|                                                              |        |      |                                         |
| 74                                                           |        |      |                                         |
|                                                              |        |      |                                         |
| 875                                                          |        |      |                                         |
| 1011                                                         |        |      |                                         |



### <a name="HashTable">HashTable</a>

| [题目](https://leetcode-cn.com/problemset/all/)          | 完成日 | 难度 | 解答 |
| -------------------------------------------------------- | ------ | ---- | ---- |
| [1. 两数之和](https://leetcode-cn.com/problems/two-sum/) | 9-04   | I    |      |
|                                                          |        |      |      |
|                                                          |        |      |      |
|                                                          |        |      |      |
|                                                          |        |      |      |
|                                                          |        |      |      |

### <a name="list">List</a>

| [题目](https://leetcode-cn.com/problemset/all/) | 完成日 | 难度 | 解答                             |
| ------------------------------------------------------------ | ------ | ---- | -------------------------------- |
| [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/) | 2-15   | I    | [分类讨论](notes/leetcode0002.md) |
| [445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/) | 2-15 | I | [利用栈](notes/leetcode0445.md) |
| [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/) | 2-15 | II | **[封装](notes/leetcode0024.md)** |
|  |  |  |  |
| [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) | 2-25 | I | [迭代](notes/leetcode0206.md) |
| [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 2-25 | II | [迭代](notes/leetcode0092.md) |
|  |  | | |
| [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) | 2-25 | II | [快慢指针](notes/leetcode0141.md) |
| [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) | 2-25 | II | [双指针](notes/leetcode0142.md) |
|                                                              |        |      |                                  |
| [23. 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) | | | |
| 21 | | | |
|  | | | |
| 147 | | | |

### Stack



| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                              |
| ------------------------------------------------------------ | ------ | ---- | --------------------------------- |
| [150. 逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/) | 3-22   | II   | [后缀求值](notes/leetcode0150.md) |
|                                                              |        |      |                                   |





### <a name="string">String</a>

[**花花的String讲解视频列表**](https://www.youtube.com/playlist?list=PLLuMmzMTgVK49Hph4vV8DAzGZpj4azwmz)

[花花酱油管题目列表](https://www.youtube.com/playlist?list=PLLuMmzMTgVK49Hph4vV8DAzGZpj4azwmz)

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                          |
| ------------------------------------------------------------ | ------ | ---- | ----------------------------- |
| [551. 学生出勤记录 I](https://leetcode-cn.com/problems/student-attendance-record-i/) |        |      | [题目](notes/leetcode0551.md) |
| 139                                                          |        |      |                               |
| 241                                                          |        |      |                               |
| 676                                                          |        |      |                               |
| 451                                                          |        |      |                               |
| 680                                                          |        |      |                               |

[算法训练营第20课：字符串算法](第20课丨字符串算法.md)

| [题目](https://leetcode-cn.com/problemset/all/)              | 完成日 | 难度 | 解答                                                         |
| :----------------------------------------------------------- | :----- | ---- | ------------------------------------------------------------ |
| **字符串基础问题**                                           |        |      |                                                              |
| [709. 转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/) | 2-26   | 0    | [ASCII值](notes/leetcode0709.md)                             |
| [58. 最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/) | 2-26   | 0    | [string方法](notes/leetcode0058.md)                          |
| [771. 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/) | 2-26   | 0    | [使用set](notes/leetcode0771.md)                             |
| [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/) | 2-26   | I    | [hash](notes/leetcode0387.md)                                |
| [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/) | 2-26   | I    | [字符串方法](notes/leetcode0008.md)                          |
| **字符串操作问题**                                           |        |      |                                                              |
| [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/) | 2-26   | I    | [前缀匹配](notes/leetcode0014.md)                            |
| [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/) | 2-26   | 0    | [reverse方法](notes/leetcode0344.md)                         |
| [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/) | 2-26   | 0    | [使用reverse](notes/leetcode0541.md)                         |
| · https://leetcode-cn.com/problems/reverse-words-in-a-string/ |        |      |                                                              |
| · https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/ |        |      |                                                              |
| · https://leetcode-cn.com/problems/reverse-only-letters/     |        |      |                                                              |
| **异位词问题**                                               |        |      |                                                              |
| [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/) | 2-26   | 0    | [解答](notes/leetcode0242.md)                                |
| [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/) |        |      |                                                              |
| [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) | 2-26   | II   | **[滑动窗口](notes/leetcode0438.md)**                        |
| **回文串问题**                                               |        |      |                                                              |
| · https://leetcode-cn.com/problems/valid-palindrome/         |        |      |                                                              |
| · https://leetcode-cn.com/problems/valid-palindrome-ii/      |        |      |                                                              |
| · https://leetcode-cn.com/problems/longest-palindromic-substring/ |        |      |                                                              |
| **最长子串、子序列问题**                                     |        |      |                                                              |
| · https://leetcode-cn.com/problems/longest-common-subsequence/ |        |      |                                                              |
| · https://leetcode-cn.com/problems/edit-distance/            |        |      |                                                              |
| · https://leetcode-cn.com/problems/longest-palindromic-substring/ |        |      |                                                              |
| **字符串+DP问题**                                            |        |      |                                                              |
| [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/) |        |      | [详细讲解](https://leetcode-cn.com/problems/regular-expression-matching/solution/ji-yu-guan-fang-ti-jie-gen-xiang-xi-de-jiang-jie-b/) |
| · https://leetcode-cn.com/problems/wildcard-matching/        |        |      |                                                              |
| · https://leetcode-cn.com/problems/distinct-subsequences/    |        |      |                                                              |
| **课后作业**                                                 |        |      |                                                              |
|                                                              |        |      |                                                              |

### [王道机试指南](王道机试指南.pdf)

| 题目                                                         | 完成日 | 难度 | 解答                            |
| ------------------------------------------------------------ | ------ | ---- | ------------------------------- |
| [哈夫曼树](https://www.nowcoder.com/questionTerminal/162753046d5f47c7aac01a5b2fcda155) | 2-27   | I    | [优先级队列](notes/哈夫曼树.md) |
| [二叉排序树](https://www.nowcoder.com/questionTerminal/b42cfd38923c4b72bde19b795e78bcb3) | 2-27   | I    | [递归插入](notes/二叉排序树.md) |
| [二叉搜索树](https://www.nowcoder.com/questionTerminal/3d6dd9a58d5246f29f71683346bb8f1b?toCommentId=1171789) | 2-27   | I    | [建树](notes/二叉搜索树.md)     |
| [畅通工程](https://www.nowcoder.com/questionTerminal/4878e6c6a24e443aac5211d194cf3913?orderByHotValue=1&page=1&onlyReference=false) |        | II   | [并查集/DFS](notes/畅通工程.md) |





## 刷题方法

方法来自花花酱的视频：[油管链接](https://www.youtube.com/watch?v=NdWYxz3izH4)

1. 要刷多少题

- 每个类型 16-20 题（动态规划：多多益善）

- 总共 200~300题

2. 如何刷题

- 同类型的题目一起刷。e. g・周一:树/链表,周二:搜索，周三：动态规划，。。。
- 第一遍：5 分钟想不出来就看答案
- 第二遍：尝试不看答案完整实现（一道题不要超过 60 分钟）
- 第三遍：尝试快速实现，如果 15-20 分钟内实现不了就看答案

3. 看代码很重要！

- 看至少 3~5 种不同的实现，分析别人的代码, 优缺点, 为什么速度快/慢? 
- 学习新的语言/算法/数据结构/API/模版/最佳实践

4. 培养的能力

- 扩宽的思路，至少能看出该使用什么样的算法
- 数据规模-> 时间复杂度推算
- 代码风格：1. 一致性：命名/缩进/括号/換行 2.有意义的变量名

## 