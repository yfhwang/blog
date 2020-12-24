#将notes/*.assets文件夹下的照片拷贝到images文件夹下
path=`pwd`/notes

filelist=`ls $path`
for file in $filelist; do	#遍历文件夹
	if [ -d $path/$file ]; then	#如果是个文件夹

		ls $path/$file | while read line; do
			cp -rf "$path/$file/$line" `pwd`/images
			#echo $line
		done


		#cp -rf $path/$file/$img `pwd`/images

		#echo $path/$file
	fi
	#cp -rf $path/$file dir 
done