## [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

### 题目描述

难度中等

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 `null`。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。

**说明：**不允许修改给定的链表。

 

**示例 1：**

```
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
```

![img](../images/circularlinkedlist-20200225142625512.png)

**示例 2：**

```
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
```

![img](../images/circularlinkedlist_test2-20200225142625613.png)

**示例 3：**

```
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。
```

![img](../images/circularlinkedlist_test3-20200225142625645.png)

 

**进阶：**
你是否可以不用额外空间解决此题？

### 分析

题目分析

### 解法一

HashTable

```c++
//36ms, 12.1MB
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode *p=head;
        while(p){
            if(visited.count(p)) return p;
            visited.insert(p);
            p=p->next;
        }
        return nullptr;
    }
};
```

### 解法二

考点：

- 双指针链表判环

题解：

- 使用双指针判断链表中是否有环，ptr1慢指针每次走一步，ptr2快指针每次走两步，若链表中有环，则两指针必定相遇。
- 假设环的长度为l，环上入口距离链表头距离为a，两指针第一次相遇处距离环入口为b，则另一段环的长度为c=l-b，由于ptr2走过的距离是ptr1的两倍，则有a+l+b=2*(a+b),又有l=b+c，可得a=c，故当判断有环时(ptr1==ptr2)时，从头移动ptr1，同时移动ptr2，两指针相遇处即为环的入口。

```c++
//16ms, 9.9MB
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)	return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) { //ptr2快指
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {          //快慢指针相遇
                slow = head;    		//从头移动ptr1
                while(slow != fast)	{	//同时移动ptr1和ptr2
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;		//两指针相遇处即为环的入口
            }
        }
        return nullptr;
    }
};
```

