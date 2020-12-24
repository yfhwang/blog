@echo off
echo "windows .bat call .shell script"
"C:\Program Files\Git\bin\sh.exe" --login -i -c "sh f:/mynuts/blog/getsidebar.sh"

F:
cd ./mynuts/blog
start /B docsify serve ./docs --open