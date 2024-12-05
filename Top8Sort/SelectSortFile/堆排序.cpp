#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int n, int i) // 將一個無序的數組成大根堆，时间复杂度O(logn)，空间复杂度O(1)
{
    int largest = i;       // 初始化最大值为根节点
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于最大值节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // 递归地堆化受影响的子树
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int> &arr) // 时间复杂度O(nlogn)，空间复杂度O(1)
{
    int n = arr.size();

    // 构建堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个个从堆中取出元素
    for (int i = n - 1; i > 0; i--)
    {
        // 移动当前根到末尾
        swap(arr[0], arr[i]);

        // 调整堆
        heapify(arr, i, 0);
    }
}
void pritn(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int a[10] = {4, 6, 3, 5, 9};
    vector<int> arr(a, a + 5);
    pritn(arr);
    heapSort(arr);
    cout << "排序后" << endl;
    pritn(arr);
    return 0;
}