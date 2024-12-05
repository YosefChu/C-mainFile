#include<iostream>
#include<vector>   
using namespace std;
void BubbleSort(vector<int> &arr, int n) // 時間複雜度O(n^2) 空間複雜度O(1)
{
    for (int i = 0; i < n - 1;i++)
        for (int j = 0; j < n -i- 1;++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
}

int main()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=rand()%100;
    }
    vector<int> arr(a, a + 10);
    BubbleSort(arr, 10);
    for(auto i:arr)
    {
        cout << i << " ";
    }
}