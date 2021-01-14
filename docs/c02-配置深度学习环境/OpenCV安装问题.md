`sudo apt-get install python-numpy`



ImportError: libSM.so.6: cannot open shared object file: No such file or directory

安装opencv时候缺少库，无脑解决方案

apt-get update

apt-get install -y libsm6 libxext6 libxrender-dev

pip install opencv-python