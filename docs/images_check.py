# -*- coding: utf-8 -*-
import os
import re

pwd = os.getcwd()   # 当前路径

if os.path.exists("images_names.txt"):  # 如果文件存在
    # 删除文件，可使用以下两种方法。
    os.remove("images_names.txt") 
    

#遍历一个md文件的所有行
def walkFile(filename):
    img_list = []
    # print("filename:", filename)   
    fo = open(filename,"r")
    out = open("images_names.txt", "a+")
    lines = fo.readlines()
    pattern = re.compile(r'(?<=../images/).*?(?=\))')   # 查找数字
    for line in lines:
        if(re.match(r'.*(?=../images/).*', line, 0)):   # 判断这一行中是否有img
                # print(pattern.findall(line)[0])
                if pattern.findall(line):
                    out.write(pattern.findall(line)[0])
                    out.write("\n")
    fo.close()
    out.close()


# 遍历dir文件夹下的所有.md文件
def walkDir(dir):
    for _, _, files in os.walk(dir):  
        for file in files:
            if re.match(r'.+(?=[.md]$)', file, 0):
                walkFile(dir + "/" + file)



for _, dirs, _ in os.walk(pwd):  
    for dir in dirs:
        if dir != "images":
            dir = pwd + "/" + dir
            walkDir(dir) #遍历当前路径下所有子目录
    break


# 所有已经访问过的图片
used_images = []
with open("images_names.txt", "r") as f:
    for line in f.readlines():
        used_images.append(line.replace('\n',''))
# print(used_images)

# 存在的图片中,删除没有访问过的图片
img_path = pwd + "/images"
for _, _, files in os.walk(img_path):
    for file in files:
        if file in used_images:
            print("exist:", file)
        else:
            print("delete:", file)
            os.remove(os.path.join(img_path, file))
