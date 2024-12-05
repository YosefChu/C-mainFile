#include <iostream>
#include <vector>
using namespace std;
void pritn(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
void selectSort(vector<int> &arr) // 時間複雜度O(n^2)空間複雜度O(1)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++) //
    {
        int minkey = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minkey]) // 从 n 个元素中找出关键字最小的元素与第一个元素交换；
            {
                minkey = j;
            }
        }
        if (minkey != i)
        {
            swap(arr[i], arr[minkey]);
        }
    }
}
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 100;
    }
    vector<int> arr(a, a + 10);
    selectSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}