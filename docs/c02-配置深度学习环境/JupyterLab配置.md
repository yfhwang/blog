# JupyterLab配置

https://blog.csdn.net/Wonz5130/article/details/82258603

https://zhuanlan.zhihu.com/p/48387217

https://blog.csdn.net/cloud1980_cn/article/details/86776274

官方文档：https://jupyterlab.readthedocs.io/en/stable/

119.45.59.115

## 卸载python

### 方法1

重新打开安装python的文件夹进行卸载

### 方法2

1. 找到Python的安装路径，删除所有文件
2. 删除环境变量

### python指向设置



```bash
#查看python的指向
ls -l /usr/bin | grep python
#安装python3.7
apt-get install python3.7
#删除原有链接
rm /usr/bin/python3
#建立新链接
ln -s /usr/bin/python3.7 /usr/bin/python3
```

```bash
#安装pip3
sudo apt-get install python3-pip
```



## 安装Aaconda

### 下载地址：

https://mirrors.tuna.tsinghua.edu.cn/anaconda/archive/

https://repo.anaconda.com/archive/

版本对应的Python版本

| Anaconda版本 | Python版本 |
| ------------ | ---------- |
| 5.3以后      | 3.7        |
| 5.2          | 3.6        |

### windows安装

下载完成后双击即可

### Linux安装

1. 将Anaconda3-5.0.1-Linux-x86_64.sh文件复制到~文件夹下
2. 使用`bash Anaconda3-5.0.1-Linux-x86_64.sh`命令安装anaconda，过程中可能需要输入yes
3. 配置环境变量，添加~/.bashrc文件，输入`export PATH=~/anaconda3/bin:$PATH`





## 设置国内源

### conda

在 cmd 中分别运行下面两个命令。

```bash
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes
```

然后，检查一下 .condarc 文件是否是下面这样的内容 (推荐使用 everything 进行搜索这个文件，注意带. 的)，或者你可以直接修改该文件的内容设置镜像。

```
channels:
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
  - defaults
show_channel_urls: true
ssl_verify: true
```

### pip

#### 升级pip

```text
sudo apt-get install python-pip
sudo pip install --upgrade pip
```



#### 国内源

- 阿里云 [http://mirrors.aliyun.com/pypi/simple/](https://link.zhihu.com/?target=http%3A//mirrors.aliyun.com/pypi/simple/)
- 中国科技大学 [https://pypi.mirrors.ustc.edu.cn/simple/](https://link.zhihu.com/?target=https%3A//pypi.mirrors.ustc.edu.cn/simple/)
- 豆瓣(douban) [http://pypi.douban.com/simple/](https://link.zhihu.com/?target=http%3A//pypi.douban.com/simple/)
- 清华大学 [https://pypi.tuna.tsinghua.edu.cn/simple/](https://link.zhihu.com/?target=https%3A//pypi.tuna.tsinghua.edu.cn/simple/)
- 中国科学技术大学 [http://pypi.mirrors.ustc.edu.cn/simple/](https://link.zhihu.com/?target=http%3A//pypi.mirrors.ustc.edu.cn/simple/)

- 临时使用

```
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple some-package
```

- 永久更改pip源

升级 pip 到最新的版本 (>=10.0.0) 后进行配置：

```
pip install pip -U
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
```

如果您到 pip 默认源的网络连接较差，临时使用镜像站来升级 pip：

```
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U
```

####  pip指向问题

有时候会出现`pip,pip2,pip3`都TM指向`python2`，这个之后就需要改一下这这三个文件。

编辑这三个文件，将第一行注释分别改为python\python2\python3

```text
~ $which pip
/usr/local/bin/pip
21:36 alien@alien-Inspiron-3443:
~ $which pip2
/usr/local/bin/pip2
21:36 alien@alien-Inspiron-3443:
~ $which pip3
/usr/local/bin/pip3
```



## 安装nodejs

1. 去 nodejs 官网 https://nodejs.org 看最新的版本号；
   \#求稳的话建议选 10.16.0 的LTS版。

   https://nodejs.org/en/download/

2. 添加源后安装
   nodejs 的每个大版本号都有相对应的源，比如 10.x.x版本的源是https://deb.nodesource.com/setup_10.x。

所以在终端执行：

```bash
#更新ubuntu软件源
sudo apt-get update
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash - 
```

稍等片刻，源已经添加完毕，再执行：

```bash
sudo apt-get install nodejs
```

## 安装jupyterlab

直接使用conda或者pip安装即可

```
jupyter lab clean
jupyter lab build 
```

## 云端配置

### 创建密码

```bash
python3
from notebook.auth import passwd
passwd()
# 输入你自己设置登录JupyterLab界面的密码，
# 然后就会生产下面这样的密码，将它记下来，待会儿用
'sha1:b6b617bc3df8:4890688cbd5d4690baabc5cbaf633512b6456426'
```



### 修改配置文件

先生成一个配置文件，记下输出的配置文件地址

```text
jupyter lab --generate-config
/root/.jupyter/jupyter_notebook_config.py
/Users/ivanhuang/.jupyter
```

修改配置文件，找到下面这几行文件，注释掉并修改成这样。

```text
c.NotebookApp.allow_root = True
c.NotebookApp.ip = '0.0.0.0'
c.NotebookApp.notebook_dir = u'/root/JupyterLab'
c.NotebookApp.open_browser = False
c.NotebookApp.password = u'sha1:b92f3fb7d848:a5d40ab2e26aa3b296ae1faa17aa34d3df351704'
'sha1:bdd5388a5303:3c4ada47b9e5dcf28d7f7d583ff20f5c8a8b332a'
c.NotebookApp.port = 8080
```

还需要在 /root/目录下创建JupyterLab文件夹



对应每行稍微解释一下

```text
允许以root方式运行jupyterlab
允许任意ip段访问
设置jupyterlab页面的根目录
默认运行时不启动浏览器，因为服务器默认只有终端嘛
设置之前生产的哈希密码
设置访问端口
```

到此，`JupyterLab`已经安装成功了。

```text
jupyter-lab --version
0.33.12
jupyter lab build
```

`jupyter lab build`时间有点久，如果没报错就成功了。但此时你还不能访问`JupyterLab`。，还需要添加端口规则，也就是所谓的添加安全组，打开8080端口。

### 后台运行

```bash
# nohup表示ssh终端断开后仍然运行
# &表示允许后台运行
nohup jupyter lab &

#显示后台进程
ps aux | grep jupyter
#杀死进程
kill -9 进程号
```

浏览器输入`公网ip:8080`，就可以访问你的`JupyterLab`了，第一次访问比较慢，耐心一点，如果最终还是无法访问，那么就是你的安全组配置错啦。

**解释**

-  用`&`让命令后台运行, 并把标准输出写入jupyter.log中

- `nohup`表示no hang up, 就是不挂起, 于是这个命令执行后即使终端退出, 也不会停止运行.

### 开机自启

```
sudo nano /etc/rc.local

在文本编辑器中增加：
touch /var/lock/subsys/local
jupyter lab --allow-root
```





## 安装插件与配置

ref：

https://zhuanlan.zhihu.com/p/101070029

https://zhuanlan.zhihu.com/c_173369508

### ipykernel

```
pip install ipykernel
```

安装内核

```python
#此命令中第一个python2 是自己之前对多版本的python安装进行的设置，用于与python3区分开。
#第二个Python2 为安装内核后，在jupyterlab中显示的内核名字（可自定义）。其他命令不用改
python -m ipykernel install --name python2.7
python3 -m ipykernel install --name python3

#查看jupyter notebook kernel
jupyter kernelspec list
#删除notebook kernel
jupyter kernelspec remove kernelname
```

### toc

ref：

https://www.cnblogs.com/IvyWong/p/10133389.html#2745022321

1. 安装npm和nodejs

- JupyterLab >=2.0
- NodeJS (建议选 10.16.0 的LTS版)

```bash
#检查版本
node -v
npm -v
```

```bash
#安装jupyter_contrib_nbextensions
pip install jupyter_contrib_nbextensions
#安装javascript和css文件
jupyter contrib nbextension install --user
#安装jupyterlab-toc
jupyter labextension install @jupyterlab/toc
```

### sublime

```bash
jupyter labextension install @ryantam626/jupyterlab_sublime
```

### definition

```bash
jupyter labextension install @krassowski/jupyterlab_go_to_definition
```

### kite

#### 下载kite

https://kite.com/

#### need

jupyter lab >= 2.2.0a1

```bash
pip install --pre jupyterlab==2.2.0a1
```

nodejs：

```bash
conda install nodejs=10.13
```

#### jupyter-kite

```bash
pip install jupyter-kite
jupyter labextension install @kiteco/jupyterlab-kite
```

### 有用的库

```
pip install ipython matplotlib scipy pandas numpy
```

## 其他设置

### 自动输出结果

参考：https://www.cnblogs.com/ly123456/p/12372618.html

```python
from IPython.core.interactiveshell import InteractiveShell
InteractiveShell.ast_node_interactivity = "all"
```

**永久更改方法**

```
/Users/ivanhuang/.ipython/profile_default

在修改默认目录时，cmd执行： jupyter notebook --generate-config
生成的文件夹 .ipython 中
进入路径：C:\Users\Administrator\.ipython\profile_default 
新建文件：ipython_config.py
输入内容：

c = get_config()
c.InteractiveShell.ast_node_interactivity = "all"

保存，关闭文件。
重启 Jupyter notebook 后，即可直接多行结果输出。
```



## 使用技巧

### 命令模式快捷键

| 按键             | 功能                                |
| ---------------- | ----------------------------------- |
| Shift + Up       | 同时选择上一个cell                  |
| ctrl + shift + - | 分割cell                            |
| shift + M        | 合并cell                            |
| 数字键1到6       | 将当前块第一行变为MarkDown的n级标题 |



### 合并ipynb文件

```javascript
pip install nbmerge
```

用法

```bash
nbmerge file_1.ipynb file_2.ipynb file_3.ipynb > merged.ipynb
```




























