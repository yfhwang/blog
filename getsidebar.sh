# src=F:/mynuts/blog/docs
src=/Users/ivanhuang/Desktop/blog/docs
sidebar=$src/_sidebar.md
: > $sidebar   #清空sidebar文件
echo "* [简介]()" >> $sidebar
for file_or_dir in `ls $src/`	#遍历文件夹
do
	if [ "$file_or_dir" = "images" ];then	#images不用输出到目录中
		echo $file_or_dir
	elif [ "$file_or_dir" = "README.md" ]; then
		echo $file_or_dir
	elif [ "$file_or_dir" = "_sidebar.md" ]; then
		echo $file_or_dir
	elif [ "$file_or_dir" = "ignore/" ]; then
		echo $file_or_dir
	else
    	if [[ $file_or_dir =~ ".md" ]];then	#如果file以.md结尾
			echo "* [${file_or_dir%.md*}]($file_or_dir)" >> $sidebar
		
		elif [ -d $src/$file_or_dir ];then	#如果file是文件夹
			echo "* ${file_or_dir%/}" >> $sidebar
			for subfile in $src/$file_or_dir/*	#遍历子文件夹
			do
				#if  [[ $subfile =~ ".md" ]];then
					subfile_temp="${subfile%.md*}"
					subfile_src="${subfile%/*}"
					subfile_src="${subfile_src##*/}"

					echo "  * [${subfile_temp##*/}]($subfile_src/${subfile##*/})" >> $sidebar
				#fi
			done
		else #[[ $file_or_dir =~ "." ]]; then  如果file以.结尾
			echo $file_or_dir
		fi
	fi
done 
