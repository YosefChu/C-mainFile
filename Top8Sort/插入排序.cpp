#include<iostream>
#include<vector>   
using namespace std;
void print(vector<int>& arr)
{
    for (int i = 0; i < arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertSort(vector<int> &arr) // 時間複雜度O(n^2) 空間複雜度O(1)
{
    int n =arr.size();
    for (int i = 0; i < n;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0&&arr[j]>key)//從後往前找到比key小的元素
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertSort(arr);
    print(arr);
    return 0;
}