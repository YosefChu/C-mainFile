#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int> &arr,int i,int t)
{
    int lagrest = i;
    int left = 2 * i + 1;
    int right = 2 * i+2;

    if (left < t && arr[left] > arr[lagrest])
    {
        lagrest = left;
    }
   if(right<t&&arr[right]>arr[lagrest])
   {
       lagrest = right;
   }
   if (lagrest!=i)
   {
       swap(arr[i], arr[lagrest]);

       heapify(arr, lagrest, t);
   }
   
}
void heapSort(vector<int> &arr)
{
    int a=arr.size();
    for(int i = a/2-1;i>=0;i--)
    {
        heapify(arr,i,a);
    }
    for(int i = a-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
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
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 100;
    }
    vector<int> arr(a, a + 10);
    pritn(arr);
    heapSort(arr);
    cout<<"排序后"<<endl;
    pritn(arr);
    return 0;
}