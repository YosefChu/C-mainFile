
#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include "HuffmanNode.h"
using namespace std;
// MinHeap 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
//  ******************PUBLIC OPERATIONS*********************
// void insert(const T &x)  --> 插入元素 x
// const T & findMin() const  --> 返回最小元素
// void deleteMin()  --> 删除最小元素
// bool isEmpty() const  --> 判断堆是否为空
// void makeEmpty()  --> 清空堆
// ******************ERRORS********************************

class Minheap // 哈夫曼树的最小堆，用于合并权重最小的两个节点
{
public:
    HuffmanNode *root; // 哈夫曼树的根节点，用于编码和解码，哈夫曼树的根节点不代表具体字符，只是所有字符的合并结果　
    int size;          // 当前容量
    int capacity;      // 最大容量
    int parent(int i)
    {
        return (i - 1) / 2; // 返回父节点的位置
    }
    int left(int i)
    {
        return (2 * i + 1); // 返回父节点的位置
    }
    int right(int i)
    {
        return (2 * i + 2); // 返回右节点的位置
    }
    void heapifyDown(int index)// 从index开始向下调整堆，使得堆满足最小堆的性质，即父节点的权重小于子节点的权重，如果不满足则交换父节点和子节点，然后继续向下调整，直到满足最小堆的性质，或者到达叶子节点，时间复杂度为O(logn)，n为堆的大小，即哈夫曼树的节点个数，空间复杂度为O(1)，不需要额外的空间，是原地排序算法
    {
        int smallest = index;
        int l = left(index);
        int r = right(index);
        if (l < size && root[l].NumberOfCharacters < root[smallest].NumberOfCharacters)
        {
            smallest = l;
        }
        else if (r < size && root[r].NumberOfCharacters < root[smallest].NumberOfCharacters)
        {
            smallest = r;
        }
        if (smallest != index)
        {
            swap(root[index], root[smallest]);
            heapifyDown(smallest);
        }
    }
    Minheap(int _capacity) // 构造函数，初始化哈夫曼树，哈夫曼树的根节点为空，当前容量为0，最大容量为_capacity
    {
        capacity = _capacity;
        size = 0;
        root = new HuffmanNode[capacity];
    }
    ~Minheap() // 析构函数，释放哈夫曼树的内存
    {
        delete root;
    }
    void insert(HuffmanNode node) // 插入一个节点到哈夫曼树中
    {
        if (size == capacity)
        {
            cout << "哈夫曼树已经满了" << endl;
            return;
        }
        root[size] = node;
        size++;
    }
    HuffmanNode TakeHuffmanNodeMinNumberOfCharacters() // 提取哈夫曼树中权重最小的节点
    {
        if (size == 0)
        {
            cout << "哈夫曼树为空" << endl;
            return HuffmanNode();
        }

        HuffmanNode min = root[0];
        root[0] = root[size - 1];
        size--;
        heapifyDown(0);
        return min;
    }
    int getSize() // 返回当前容量
    {
        return size;
    }
};
#endif