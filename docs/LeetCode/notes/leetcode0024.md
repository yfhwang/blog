## [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

难度中等

### 题目描述

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

### 分析

每个循环向后移动两个位置

先判断head和head->next是否为空，接下来按顺序调整指针即可

### 解法一 

篮子王的解答，把循环内的内容封装成函数，答题的结构非常清晰

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);	//头节点的前一个节点
        dummy->next = head;
        ListNode *current = dummy;
        while(current->next && current->next->next){	//当current的后连个节点均存在时，继续循环
            swapNextTwoNodes(current);
            current = current->next->next;
        }
        return dummy->next;
    }
    void swapNextTwoNodes(ListNode *pre){	//交换pre的后两个节点
        ListNode *p1=pre->next;
        pre->next=p1->next;
        p1->next=p1->next->next;
        pre->next->next=p1;
    }
};
```

### 解法二

我的解答：做题30min

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//执行用时 :4 ms, 在所有 C++ 提交中击败了81.50%的用户
//内存消耗 :8.6 MB, 在所有 C++ 提交中击败了69.25%的用户
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *p1=head;
        ListNode *p2=p1->next;
        head = p2;
        
        ListNode *p1Pre = new ListNode(0);
        ListNode *p2Next;
        while(p1 && p2){
            //把p1、p2重新连接
            p2Next = p2->next;  
            p1->next = p2Next;
            p2->next = p1;
            p1Pre->next = p2;
            //给p1，p2重新赋值
            p1Pre=p1;
            p1=p2Next;
            if(p2Next){
                p2=p2Next->next;
            }else{
                break;
            }
        }
        return head;
    }
};
```

### 