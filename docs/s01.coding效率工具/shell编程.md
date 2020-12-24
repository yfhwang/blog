# shell常用命令

windows下的类似linux下的grep命令——findstr



# shell编程

## 参考

- [十分钟学会写shell脚本blog](https://www.cnblogs.com/handsomecui/p/5869361.html)

## Windows下安装与调试

### 从git官网下载git并安装 

安装好后，查看环境变量是否配置正确`C:\Program Files\Git\cmd`

### 测试

打开git bash窗口

```bash
#创建文件
touch test.sh
#输入内容
a="hello world!"
num=2
echo "a is : ${a}, num is : ${num}nd"
#运行脚本
./test.sh
sh test.sh
/bin/sh test.sh
```



## if语句

### 两个例子

注意if的空格以及[]里面的空格

```bash
if [ "$SHELL" ="/bin/bash" ];then
	echo "your login shell is the bash\n"
	echo "SHELL is : $SHELL"
else
	echo "your login shell is not bash but $SHELL"
fi
```



```bash
[ -f "/etc/shadow" ] && echo "This computer uses shadow passwords"
if [ -f "/etc/shadow" ];then
	echo "电脑密码使用隐藏字符"
else
	echo "并没有"
fi
```

### if后的判断语句

| if后的判断语句    | 含义                              |
| ----------------- | --------------------------------- |
| [ -f "somefile" ] | 判断是否是一个文件                |
| [ -d $file ]      | 判断是否是一个文件夹              |
| [ -x "/bin/ls" ]  | 判断/bin/ls是否存在并有可执行权限 |
| { -n "$var" }     | 判断$var变量是否有值              |
| [ "\$a" = "\$b" ] | 判断\$a和\$b是否相等              |
| [ -r "$folder" ]  | 判断folder是否可读                |

### 练习

> 从一个文件里面读入有echo的语句，并把其写到另一个文件中

```bash
readme=./readme.txt
if [ -r "$readme" ];then
	echo "successfully read file"
	echo | grep '^echo ' $readme >> readme2.txt
else
	echo "cannot read file"
fi
```

## while语句









# shell截取字符串

## 参考资料

- [shell截取字符串方法总结](https://blog.csdn.net/weixin_34010566/article/details/85639338?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param)

## 截取部分字符串方法

| 操作               | 代码                 |
| ------------------ | -------------------- |
| 最小限度从前面删除 | `${parameter#word}`  |
| 最大限度从前面删除 | `${parameter##word}` |
| 最小限度从后面删除 | `${parameter%word}`  |
| 最大限度从后面删除 | `${parameter%%word}` |

详细解释

```
1、使用 # 号操作符。
用途是从左边开始删除第一次出现子字符串即其左边字符，保留右边字符。
用法为#*substr,例如：
str='http://www.你的域名.com/cut-string.html'
echo ${str#*//}
得到的结果为www.你的域名.com/cut-string.html，即删除从左边开始到第一个"//"及其左边所有字符

2、使用 ## 号操作符。
用途是从左边开始删除最后一次出现子字符串即其左边字符，保留右边字符。
用法为##*substr,例如：
str='http://www.你的域名.com/cut-string.html'
echo ${str##*/}
得到的结果为cut-string.html，即删除最后出现的"/"及其左边所有字符

3、使用 % 号操作符。
用途是从右边开始删除第一次出现子字符串即其右边字符，保留左边字符。
用法为%substr*,例如：
str='http://www.你的域名.com/cut-string.html'
echo ${str%/*}
得到的结果为http://www.你的域名.com，即删除从右边开始到第一个"/"及其右边所有字符

4、使用 %% 号操作符。
用途是从右边开始删除最后一次出现子字符串即其右边字符，保留左边字符。
用法为%%substr*,例如：
str='http://www.你的域名.com/cut-string.html'
echo ${str%%/*}
得到的结果为http://www.你的域名.com，即删除从右边开始到最后一个"/"及其右边所有字符
```









