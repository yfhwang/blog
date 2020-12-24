## [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

### 题目描述

难度中等

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 **[深拷贝](https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin)**。 

我们用一个由 `n` 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：

- `val`：一个表示 `Node.val` 的整数。
- `random_index`：随机指针指向的节点索引（范围从 `0` 到 `n-1`）；如果不指向任何节点，则为 `null` 。

 

**示例 1：**

![img](../images/e1.png)

```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**示例 2：**

![img](../images/e2.png)

```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
```

**示例 3：**

**![img](../images/e3.png)**

```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
```

**示例 4：**

```
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
```

 

**提示：**

- `-10000 <= Node.val <= 10000`
- `Node.random` 为空（null）或指向链表中的节点。
- 节点数目不超过 1000 。

### 分析

1. 第一遍扫描：拷贝所有节点，只复制的value值
2. 第二遍扫描：拷贝next和random指针

### 解法一

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> ump;
        Node *cur = head;
        Node *p;
        while(cur) { //第一遍扫描：拷贝所有节点，只复制的value值
            p = new Node(cur->val);
            ump[cur] = p;
            cur = cur->next;
        }
        cur = head;
        while(cur) {    //第二遍扫描：拷贝next和random指针
            ump[cur]->next = ump[cur->next];
            ump[cur]->random = ump[cur->random];
            cur=cur->next;
        }
        return ump[head];
    }
};
```

### 解法二

解法一重写

```c++
//8ms
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        unordered_map<Node*,Node*> m;
        Node *curr = head;
        Node *p;
        //第一遍扫描，添加节点
        while(curr) {
            p=new Node(curr->val);
            m[curr] = p;
            curr = curr->next;
        }
        //第二遍扫描，添加两个链接
        for(Node* node = head;node!=nullptr;node = node->next) {
            m[node]->next = m[node->next];
            m[node]->random = m[node->random];
        }
        return m[head];
    }
};
```

