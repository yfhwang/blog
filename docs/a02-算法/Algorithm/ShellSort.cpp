#include <iostream>
using namespace std;

// 希尔排序：缩小增量排序

// 每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。


void ShellSort(int *a, int len)
{
    int i;
    int j;
    int temp;
    int gap;  //步长
    for (gap = len / 2; gap >= 1; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半
        for (i = 0 + gap; i < len; i += gap) {   //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
            temp = a[i];  //备份a[i]的值
            j = i - gap;  //j初始化为i的前一个元素（与i相差gap长度）
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];  //将在a[i]前且比temp的值大的元素向后移动一位
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}
int main() {
    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,
                 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    int len = (int)sizeof(arr) / sizeof(*arr);
    ShellSort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
