#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class UnionFind
{
private:
    vector<int> parent;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unionset(int i, int j)
    {
        int i_f = find(i);
        int j_f = find(j);
        parent[i_f] = j_f;
    }
};
int main()
{
    int N;
    cout << "大一新生有多少人:";
    cin >> N;

    UnionFind UF(N);

    cout << "请输入每对朋友关系 (A B)，按Ctrl+Z结束输入:" << endl;
    int A, B;
    while (cin >> A >> B)
    {
        UF.unionset(A, B);
    }
    unordered_set<int> uniqueRoots;
    unordered_map<int, vector<int>> circles;

    for (int i = 0; i < N; ++i)
    {
        int root = UF.find(i);
        uniqueRoots.insert(root);
        circles[root].push_back(i);
    }

    cout << "朋友圈数量: " << uniqueRoots.size() << endl;
    for (const auto &circle : circles)
    {
        cout << "朋友圈: ";
        for (int student : circle.second)
        {
            cout << student << " ";
        }
        cout << endl;
    }
    return 0;
}