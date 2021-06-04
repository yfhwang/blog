#include <iostream>
using namespace std;

void Merge(int arr[], int l, int q, int r) {
    int i = 0;
    int left = l;
    int right = q + 1;
    while (left <= q && right <= r)
        arr[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
    while (left <= q)
        arr[i++] = arr[left++];
}

void MergeSort(int arr[], int l, int r) {
    if (l == r)
        return;  
    int q = (l + r) / 2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
}

int main() {
    int data[] = {9, 6, 7, 22, 20, 33, 16, 20};
    const int length = 8;

    cout << "Before sorted:" << endl;
    for (int i = 0; i < length; ++i)
        cout << data[i] << "  ";
    cout << endl;

    cout << "After sorted:" << endl;
    MergeSort(data, 0, length - 1);
    for (int i = 0; i < length; ++i)
        cout << data[i] << "  ";
    cout << endl;

    return 0;
}