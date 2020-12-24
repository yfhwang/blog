## [547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)

### 题目描述

难度中等

班上有 **N** 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 **N \* N** 的矩阵 **M**，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生**互为**朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

**示例 1:**

```
输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
```

**示例 2:**

```
输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
```

**注意：**

1. N 在[1,200]的范围内。
2. 对于所有学生，有M[i][i] = 1。
3. 如果有M[i][j] = 1，则有M[j][i] = 1。

### 分析

题目分析

### 解法一

DFS：类似#200题

用`M[i][i]==1`来表示同学`i`不属于任何一个已有的朋友圈

```c++
// Author: Huahua
// Time complexity: O(n^2)
// Space complexity: O(n)
// Running Time: 25 ms
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<int> visited(n,0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++ans;
            dfs(M, i, n, visited);
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& M, int curr, int n, vector<int>& visited) {        
        if(visited[curr])	return;
        visited[curr] = 1;
        // Visit all friends (neighbors)
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && M[curr][i])
            	dfs(M, i, n, visited);
        }
    }
};
```

同一种思路另一种写法

```c++
//32ms, 14.4MB
class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty()) return 0;
        int n = M.size();
        visited = vector<int>(n, 0);
        int circles=0;
        for (int i = 0; i < n; i++) {
            if(dfs(M,n,i))  circles++;
        }
        return circles;
    }

private:
    vector<int> visited;
    bool dfs(vector<vector<int>> &M,int n,int curr){
        if(visited[curr])   return false;
        visited[curr]=1;
        for(int i=0;i<n;i++){
            if(M[curr][i]==1)
                dfs(M,n,i);
        }
        return true;
    }
};
```





### 解法二

并查集 [Union Find](https://zxi.mytechroad.com/blog/val-structure/sp1-union-find-set/)

```c++
// Author: Huahua
// Runtime: 19 ms
class UnionFindSet {
public:
    UnionFindSet(int n) {
        parents_ = vector<int>(n + 1, 0);
        ranks_ = vector<int>(n + 1, 0);
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        if (ranks_[pu] > ranks_[pv]) {
            parents_[pv] = pu;
        } else if (ranks_[pv] > ranks_[pu]) {
            parents_[pu] = pv;
        } else {
            parents_[pu] = pv;
            ++ranks_[pv];
        }
 
        return true;
    }
    
    int Find(int id) {        
        if (id != parents_[id])
            parents_[id] = Find(parents_[id]);        
        return parents_[id];
    }
    
private:
    vector<int> parents_;
    vector<int> ranks_;
};
 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFindSet s(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (M[i][j] == 1) s.Union(i, j);
        
        unordered_set<int> circles;
        for (int i = 0; i < n; ++i)
            circles.insert(s.Find(i));
        
        return circles.size();
    }
};
```

