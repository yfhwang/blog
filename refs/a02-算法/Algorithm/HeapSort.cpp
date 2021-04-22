#include <iostream>
#include <algorithm>
using namespace std;
/*
(大顶)堆的性质:
	1. 堆中某个结点的值总是不大于其父结点的值；
	2. 堆总是一棵完全二叉树。

	arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2]  

（最大堆，有序区）
堆排序的步骤:
	1. 将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。
	2. 将堆顶与末尾元素进行交换，此时末尾就为最大值。
	3. 然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。
	4. 重复执行步骤3
*/
void heap_sort(int arr[], int len); 	// 堆排序算法
void max_heapify(int arr[], int start, int end);	// 向下建堆算法

void heap_sort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--)	// 堆的初始化, 从第一个非叶节点开始向上调整
		max_heapify(arr, i, len - 1);
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

void max_heapify(int arr[], int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { 
		if (son + 1 <= end && arr[son] < arr[son + 1]) 
			son++;//选择两个子节点中的较大者
		if (arr[dad] > arr[son]) {	// 若已经排序, 则退出循环
			return;
		} else { // 交换父子节点后, 子节点再向下交换
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}