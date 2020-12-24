# Git命令

## Github太慢

> 使用国内镜像，目前已知Github国内镜像网站有[github.com.cnpmjs.org](https://github.com.cnpmjs.org/)和[git.sdut.me/](https://git.sdut.me/)。速度根据各地情况而定，在clone某个项目的时候将github.com替换为github.com.cnpmjs.org即可。



## 常用

add push commit

checkout（丢掉工作区的内容） reset

branch （分支管理） merge（合并分支） checkout（切换分支）

直接恢复到上一个版本 git reset –hard 



git checkout readme.txt 意思就是，把readme.txt文件在工作区做的修改全部撤销，这里有2种情况，如下：

1. readme.txt自动修改后，还没有放到暂存区，使用 撤销修改就回到和版本库一模一样的状态。

2. 另外一种是readme.txt已经放入暂存区了，接着又作了修改，撤销修改就回到添加暂存区后的状态。

   其实也就是撤销到最后一次没有放入暂存区的状态。

## 配置Git

### 本地地址

```bash
git config --global user.name "ivan-mac"
git config --global user.email "zjrenivan@gmail.com"
```

### 忽略文件

```bash
.gitignore
__pycache__/
```

### 初始化仓库

```bash
git init
```

### 删除仓库

```bash
rm -zf .git
```



## 提交

commit可以一次提交很多文件，所以你可以多次add不同的文件，比如：

```bash
git add file1.txt
git add file2.txt file3.txt
git commit -m "add 3 files.”

#add 并 commit
git commit -am “Extended greeting.”
```





## 查看提交历史

```bash
git log
git log --pretty=oneline
git log --graph --pretty=oneline --abbrev-commit
git reflog
```



## 撤销修改



撤销暂存区的修改

```bash
git reset HEAD readme.txt
#git reset命令既可以回退版本，也可以把暂存区的修改回退到工作区。当我们用HEAD时，表示最新的版本。
```



丢掉工作区的内容

```bash
git checkout -- readme.txt
git checkout .
#总之，就是让这个文件回到最近一次git commit或git add时的状态。
```



删除文件后恢复或删除

```bash
rm readme.txt

#恢复
git checkout -- readme.txt

#继续删除
git rm readme.txt
git commit -m "remove test.txt"
```





## 版本回退



```bash
git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
```



```bash
git log —pretty=oneline

git checkout be017b

#检出以前的提交后，你将离开分支master，并进入Git所说的分离头指针（detached HEAD） 状态。
git reset —hard be017b
git reset --hard HEAD^

#以将项目重置到以前的提交

git checkout master

#回到分支master
```

## 找不同

```bash
git diff readme.txt
git diff HEAD --readme.txt
```





# 远端仓库

## 基本操作

```bash
git remote add origin https://github.com/yfhwang/Stanford_CS144.git
git branch -M master
```



把本地master的最新内容推送到github

```bash
git push origin master
```



## gitee

```bash
git add xx.md
git commit -m "first commit"
git remote add origin https://gitee.com/zjrenivan/computer-networking.git
git push -u origin master
```



## 从zip同步

https://stackoverflow.com/questions/15681643/how-to-clone-git-repository-from-its-zip

https://www.zhihu.com/question/53072606

## folk别人的代码后更新

```bash
git remote add upstream https://github.com/ORIGINAL_OWNER/ORIGINAL_REPO.git
git remote -v
git fetch upstream
git branch -a
#合并upstream/master
$ git merge upstream/master
```

## 解决git pull/push每次都需要输入密码问题

git config --global credential.helper store

