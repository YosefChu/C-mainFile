#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;
class Graph
{
public:
    int V;                         // 顶点个数
    unordered_set<int> visited;    // 訪問過的點
    vector<vector<int>> adjMatrix; // 二維邻接矩阵

    unordered_map<string, int> vertexMap; // 顶点映射，如A->0,B->1
    vector<string> vertexName;            // 顶点列表，如0->A,1->B

    Graph(int V)
    {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, INT_MAX)); // 初始化邻接矩阵為V*V的矩陣，並且初始化為無窮大
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i][i] = 0; // 對角線元素為0
        }
        vertexName.resize(V);
    }
    void addVertex(const string &name, const int &index)
    {
        vertexMap[name] = index;  // 將名字映射到索引
        vertexName[index] = name; // 將索引映射到名字
    }
    void addEdge(const string &start, const string &end, int w)
    {
        int u = vertexMap[start];
        int v = vertexMap[end];
        adjMatrix[u][v] = w;
    }
    void dijkstra(const string &start)
    {
        int s = vertexMap[start];
        vector<int> dist(V, INT_MAX); // 初始化距離為無窮大
        vector<int> prev(V, -1);      // 用于记录每个顶点的前驱节点
        dist[s] = 0;                  // 起始點到自己的距離為0

        for (int count = 0; count < V - 1; ++count)
        {
            int u = -1;

            // 找到当前未访问顶点中距离最小的顶点
            for (int i = 0; i < V; ++i)
            {
                if (visited.find(i) == visited.end() && (u == -1 || dist[i] < dist[u]))
                {
                    u = i;
                }
            }

            if (u == -1)
            {
                break; // 如果没有找到未访问的顶点，退出循环
            }

            visited.insert(u); // 将最小距离的顶点加入访问过的集合

            for (int v = 0; v < V; ++v)
            {
                if (adjMatrix[u][v] != INT_MAX && visited.find(v) == visited.end())
                { // 如果u到v有路徑且v沒有被訪問過
                    if (dist[v] > dist[u] + adjMatrix[u][v])
                    {                                        // 如果起始點到v的距離大於起始點到u的距離加上u到v的距離
                        dist[v] = dist[u] + adjMatrix[u][v]; // 更新起始點到v的距離
                        prev[v] = u;                         // 记录前驱节点
                    }
                }
            }
        }

        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "起始點到" << vertexName[i] << "的最短距離為: 無法到達" << endl;
            }
            else
            {
                cout << "起始點到" << vertexName[i] << "的最短距離為: " << dist[i] << endl;
                cout << "路径为: ";
                vector<int> path;
                for (int at = i; at != -1; at = prev[at])
                {
                    path.push_back(at);
                }
                reverse(path.begin(), path.end());
                for (int j = 0; j < path.size(); ++j)
                {
                    if (j > 0)
                        cout << " -> ";
                    cout << vertexName[path[j]];
                }
                cout << endl<<endl;
            }
        }
        // vector<int> dist(V, INT_MAX);                                                       // 初始化距離為無窮大
        // dist[s] = 0;                                                                        // 起始點到自己的距離為0
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 優先級隊列，用於選擇最小的距離
        // pq.push(make_pair(0, s));                                                           // 將起始點加入優先級隊列

        // while (!pq.empty())
        // {
        //     int u = pq.top().second; // 取出最小距離的點
        //     pq.pop();                // 將最小距離的點從優先級隊列中刪除

        //     if (visited.find(u) != visited.end())
        //     {
        //         continue;
        //     }
        //     visited.insert(u); // 將最小距離的點加入訪問過的點

        //     for (int v = 0; v < V; ++v)
        //     {
        //         if (adjMatrix[u][v] != INT_MAX && visited.find(v) == visited.end())
        //         // 如果u到v有路徑且v沒有被訪問過
        //         {
        //             if (dist[v] > dist[u] + adjMatrix[u][v])
        //             {                                        // 如果起始點到v的距離大於起始點到u的距離加上u到v的距離
        //                 dist[v] = dist[u] + adjMatrix[u][v]; // 更新起始點到v的距離
        //                 pq.push(make_pair(dist[v], v));      // 將v加入優先級隊列
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < V; ++i)
        // {
        //     if (dist[i] == INT_MAX)
        //     {
        //         cout << "起始點到" << i << "的最短距離為: 無法到達" << endl;
        //     }
        //     else
        //     {
        //         cout << "起始點到" << i << "的最短距離為: " << dist[i] << endl;
        //     }
    }
};

int main()
{
    cout << "你是否想要使用默认的图？（是请输入1，否请输入0）" << endl;
    int flag;
    cin >> flag;
    if (flag == 1)
    {
        int V = 7; // 顶点个数
        Graph g(V);

        // 添加顶点
        g.addVertex("肖邦乐谱", 0);
        g.addVertex("周杰伦海报", 1);
        g.addVertex("陈奕迅黑胶唱片", 2);
        g.addVertex("鼓", 3);
        g.addVertex("吉他", 4);
        g.addVertex("古筝", 5);
        g.addVertex("鼓+100元", 6);

        // 添加边
        g.addEdge("肖邦乐谱", "周杰伦海报", 0);
        g.addEdge("肖邦乐谱", "陈奕迅黑胶唱片", 50);
        g.addEdge("周杰伦海报", "陈奕迅黑胶唱片", 0);
        g.addEdge("陈奕迅黑胶唱片", "鼓", 150);
        g.addEdge("陈奕迅黑胶唱片", "吉他", 200);
        g.addEdge("周杰伦海报", "鼓", 300);
        g.addEdge("周杰伦海报", "吉他", 350);
        g.addEdge("鼓", "古筝", 100);
        g.addEdge("吉他", "古筝", 200);

        string s;
        s = "肖邦乐谱";
        g.dijkstra(s);
    }
    else
    {
        cout << "请输入图的顶点个数和边的个数，以及边的起始顶点，终止顶点和权重" << endl;
        int V;
        cout << "请输入顶点个数:";
        cin >> V;
        Graph g(V);

        cout << "请输入顶点名称:" << endl;
        for (int i = 0; i < V; ++i)
        {
            string name;
            cout << "顶点 " << i << " 的名称: ";
            cin >> name;
            g.addVertex(name, i);
        }
        int E;
        cout << "请输入边的个数:";
        cin >> E;
        for (int i = 0; i < E; ++i)
        {
            string start, end;
            int w;
            cout << "请输入边的起始顶点:";
            cin >> start;
            cout << "请输入边的终止顶点:";
            cin >> end;
            cout << "请输入边的权重:";
            cin >> w;
            g.addEdge(start, end, w);
        }

        string s;
        cout << "请输入起始顶点:";
        cin >> s;
        g.dijkstra(s);
    }
}