#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shellSort(vector<int> &arr) // 時間複雜度O(nlog^2*n) 空間複雜度O(1)
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0;gap/=2)
    {
        for (int i = gap; i < n;i++)
        {
            int key = arr[i];
            int j;
            for (j = i;j>=gap&&arr[j-gap]>key;j-=gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
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
    shellSort(arr);
    print(arr);
    return 0;
}