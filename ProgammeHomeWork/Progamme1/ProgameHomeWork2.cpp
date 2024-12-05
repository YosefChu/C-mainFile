/*
基于MyAList的应用实现

基于MyAList数据结构实现某信息管理程序，可以选择任何感兴趣的信息。以下是一个示例：

图书管理程序。图书基本信息至少包括：ISBN号、书名、作者、定价、出版发行单位、印次，程序提供：
1）图书的查找（根据图书名和ISBN号查找并显示书的基本信息）、（
2）图书上架（增加）、
3）图书下架（懒删除）、
3）图书删除功能。

-     程序人机界面可以采用可视化界面，也可以采用window系统的命令提示符窗体；

-     管理的图书数据至少为10份(通过磁盘文件进行存储)；

²  [注2]  1) 提供项目说明文档详细描述所管理的信息及程序提供的功能；2）和注1要求一样对定义的类及方法增加注释，有能力的话绘制程序的类图记录在项目说明文档中（不做强制要求）；3) 须和程序代码一起提交与程序对应的测试用数据文件。
*/
#include <iostream>
#include <string>
using namespace std;
class Book
{
public:
    string ISBM;      // ISBN号
    string title;     // 书名
    string author;    // 作者
    double price;     // 定价
    string publisher; // 出版发行单位
    int edition;      // 印次
    Book() {};
    Book(string temp_ISBM, string temp_title, string temp_author, double temp_price, string temp_publisher, int temp_edition)
    {
        ISBM = temp_ISBM;           // ISBN号
        title = temp_title;         // 书名
        author = temp_author;       // 作者
        price = temp_price;         // 定价
        publisher = temp_publisher; // 出版发行单位
        edition = temp_edition;     // 印次
    }
    void show()
    {
        cout << "ISBN号:" << ISBM << endl;
        cout << "书名:" << title << endl;
        cout << "作者:" << author << endl;
        cout << "定价:" << price << endl;
        cout << "出版发行单位:" << publisher << endl;
        cout << "印次:" << edition << endl;
    }

    ~Book() {}
    bool operator==(const Book &book)
    {
        return ISBM == book.ISBM;
    }
    friend ostream &operator<<(ostream &os, const Book &book)
    {
        os << "ISBN号:" << book.ISBM << endl;
        os << "书名:" << book.title << endl;
        os << "作者:" << book.author << endl;
        os << "定价:" << book.price << endl;
        os << "出版发行单位:" << book.publisher << endl;
        os << "印次:" << book.edition << endl;
        return os;
    }
};
template <typename T>
class ArrayBasedList
{
public:
    virtual ~ArrayBasedList() {};
    virtual void init(int cap) = 0;                // init: 初始化顺序表；
    virtual void resize(int newArraySize) = 0;     // 调整容量，包括扩容和缩容的实现；
    virtual void insert(int i, const T &data) = 0; // 在特定位置插入元素；
    virtual void remove(int i) = 0;                // 移除特定位置的元素；
    virtual void append(const T &data) = 0;        // 在最后元素后追加新元素；
    virtual void print() = 0;                      // 遍历顺序表并输出；
    virtual void find(const T &data) = 0;          // 输出特定元素的位置(使用顺序检索)；
    virtual T position(int i) = 0;                 // 输出特定位置的元素； //返回值为T类型；
    virtual bool isEmpty() = 0;                    // 判定顺序表是否为空；
    virtual int length() = 0;                      // 获得顺序表的元素数量；
};
template <class T>
class myAlist : public ArrayBasedList<T>
{
private:
    T *array;
    int Arraysize;
    int size;

public:
    void init(int cap)
    {
        array = new T[cap];
        Arraysize = cap;
        size = 0;
    }
    void resize(int newArraySize)
    {
        T *NewArray = new T[newArraySize];
        for (int i = 0; i < size; i++)
        {
            NewArray[i] = array[i];
        }
        delete[] array;
        array = NewArray;
        Arraysize = newArraySize;
    }
    void insert(int i, const T &data)
    {
        if (i < 0 || i > size)
        {
            cout << "插入位置不合法" << endl;
            return;
        }
        else
        {
            if (size == Arraysize)
            {
                resize(Arraysize * 2);
            }
            for (int j = size; j > i; j--)
            {
                array[j] = array[j - 1];
            }
            array[i] = data;
        }
        size++;
    }
    void remove(int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "删除位置不合法" << endl;
            return;
        }
        for (int j = i; j < size - 1; j++)
        {
            array[j] = array[j + 1];
        }
        size--;
        if (size < Arraysize / 4)
        {
            resize(Arraysize / 2);
        }
    }
    void append(const T &data)
    {
        if (size == Arraysize)
        {
            resize(2 * Arraysize);
        }
        array[size++] = data;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }
    void find(const T &data)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == data)
            {
                cout << "找到數據在" << i << "位置" << endl;
                return;
            }
        }
        cout << "不存在此數據" << endl;
    }
    T position(int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "超出上限或是下限" << endl;
            return T();
        }
        return array[i];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int length()
    {
        return size;
    }
    ~myAlist()
    {
        delete[] array;
    }
};
