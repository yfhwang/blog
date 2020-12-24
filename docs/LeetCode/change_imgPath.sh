#将notes/*.md文件中的"(*.assets/"改为"(../images/"
path=`pwd`/notes
replacement="(../images"
substring="\([.]*\.assets"
s1="test1"
s2="ttttest2"
filelist=`ls $path`
for file in $filelist; do	#遍历文件夹

	if [ -f $path/$file ]; then	#如果是个文件
		echo $file
		#cat $path/$file |while read line; do    #遍历所有文件的每一行
			#${line//substring/replacement}
			#echo $line	
		sed -i 's/leetcode[0-9][0-9][0-9][0-9]\.assets/\.\.\/images/g' $path/$file  #把file中所有的aaa字符串替换成bbb字符串
		#cp -rf $path/$file/$img `pwd`/images
		#echo $path/$file
	fi
	#cp -rf $path/$file dir 
done

#${string//substring/replacement}

#正则表达式
#\(.*\.assets/
