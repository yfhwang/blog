# iTerm2使用

## ref

- https://zhuanlan.zhihu.com/p/37195261

## 下载iTerm2

可以直接去官网下载：[https://www.iterm2.com/](https://link.zhihu.com/?target=https%3A//www.iterm2.com/)

安装完成后，在/bin目录下会多出一个zsh的文件。

### 使用zsh作为终端

Mac系统默认使用dash作为终端，可以使用命令修改默认使用zsh：

```bash
chsh -s /bin/zsh
```

如果想修改回默认bash，同样使用chsh命令即可：

```bash
chsh -s /bin/bash
```

## 安装oh-my-zsh

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

### 配置host

若sh语句无法下载，则可能需要配置host

```
https://www.ipaddress.com/
查看
raw.githubusercontent.com
的IP地址为
199.232.68.133
并添加到
/ect/hosts
的最后一行

此外可能还需要更新一下两个网址的IP地址
github.com
github.global.ssl.fastly.net
```

### Github太慢，使用国内镜像

> github.com.cnpmjs.org和git.sdut.me速度根据各地情况而定
>
> 在clone某个项目的时候将github.com替换为github.com.cnpmjs.org



## 安装高亮插件

```bash
zsh-syntax-highlighting
```

这是oh my zsh的一个插件，安装方式与theme大同小异：

```bash
cd ~/.oh-my-zsh/custom/plugins/
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git
vi ~/.zshrc
```

这时我们再次打开zshrc文件进行编辑。找到plugins，此时plugins中应该已经有了git，我们需要把高亮插件也加上：

```
plugins=(
	git
	zsh-syntax-highlighting
)
```

请务必保证插件顺序，zsh-syntax-highlighting必须在最后一个。

然后在文件的最后一行添加：source ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

按一下esc调出vi命令，输入:wq保存并退出vi模式。

执行命令使刚才的修改生效：

```bash
source ~/.zshrc
```

至此大功告成

## 安装主题

下载agnoster主题，执行脚本安装：

```bash
cd ~/Desktop/OpenSource
git clone https://github.com/fcamblor/oh-my-zsh-agnoster-fcamblor.git
cd oh-my-zsh-agnoster-fcamblor/
./install
```

执行上面的命令会将主题拷贝到oh my zsh的themes中：



## 命令补全

跟代码高亮的安装方式一样，这也是一个zsh的插件，叫做zsh-autosuggestion，用于命令建议和补全。

```bash
cd ~/.oh-my-zsh/custom/plugins/
git clone https://github.com/zsh-users/zsh-autosuggestions
vi ~/.zshrc
```

找到plugins，加上这个插件即可：

```
plugins=(
	git
	zsh-autosuggestions
	zsh-syntax-highlighting
)
```



## conda

```bash
conda init zsh
```



```bash
vi ~/.zshrc
#添加一行
export PATH="/opt/anaconda3/bin:$PATH"
```

## mac右键打开当前目录

当前目录下打开iTerm2

添加服务

```bash
git clone https://github.com/peterldowns/iterm2-finder-tools.git
```

然后在iterm2-finder-tools文件夹下 双击 Open iTerm.workflow 并且 单击 安装

PS.若未找到Open iTerm ，请在 系统设置->键盘->快捷键->服务->文件和文件夹 中查看 Open iTerm 一栏是否打钩。