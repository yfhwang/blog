#include<vector>
/*

（有序区，无序区）

在无序区里找一个最小的元素跟在有序区的后面。
对数组：比较得多，换得少。

选择排序思路：

1. 从无序区中寻找最小元素, 然后放到有序区的末尾 (保证无序区最小元素比有序区所有元素大)
2. 重复1,直到全部有序

*/

// 选择排序
void SelectionSort(vector<int>& v) {
	int min, len = v.size();
	for (int i = 0; i < len - 1; ++i) {
		min = i;
		for (int j = i + 1; j < len; ++j) {
			if (v[j] < v[min]) {    // 标记最小的
				min = j;
			}
		}
		if (i != min)  // 交换到前面
			swap(v[i], v[min]);
	}
}

// 模板实现
template<typename T> 
void Selection_Sort(std::vector<T>& arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;
		if(i != min)
			std::swap(arr[i], arr[min]);
	}
}