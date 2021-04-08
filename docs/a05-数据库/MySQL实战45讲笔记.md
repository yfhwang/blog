## 基础架构

> 一条SQL查询语句的执行

基本架构示意图

![download](../images/download.png)

### 连接器

```sh
mysql -h$ip -P$port -u$user -p
```

一个连接完成后进入空闲状态，可以在 show processlist 命令中看到它

### 分析器

### 优化器

### 执行器





