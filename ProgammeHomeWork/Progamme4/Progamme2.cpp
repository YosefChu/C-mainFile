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
    int V;                         // �������
    unordered_set<int> visited;    // �L���^���c
    vector<vector<int>> adjMatrix; // ���S�ڽӾ���

    unordered_map<string, int> vertexMap; // ����ӳ�䣬��A->0,B->1
    vector<string> vertexName;            // �����б���0->A,1->B

    Graph(int V)
    {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, INT_MAX)); // ��ʼ���ڽӾ����V*V�ľ�ꇣ��K�ҳ�ʼ����o�F��
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i][i] = 0; // ���Ǿ�Ԫ�؞�0
        }
        vertexName.resize(V);
    }
    void addVertex(const string &name, const int &index)
    {
        vertexMap[name] = index;  // ������ӳ�䵽����
        vertexName[index] = name; // ������ӳ�䵽����
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
        vector<int> dist(V, INT_MAX); // ��ʼ�����x��o�F��
        vector<int> prev(V, -1);      // ���ڼ�¼ÿ�������ǰ���ڵ�
        dist[s] = 0;                  // ��ʼ�c���Լ��ľ��x��0

        for (int count = 0; count < V - 1; ++count)
        {
            int u = -1;

            // �ҵ���ǰδ���ʶ����о�����С�Ķ���
            for (int i = 0; i < V; ++i)
            {
                if (visited.find(i) == visited.end() && (u == -1 || dist[i] < dist[u]))
                {
                    u = i;
                }
            }

            if (u == -1)
            {
                break; // ���û���ҵ�δ���ʵĶ��㣬�˳�ѭ��
            }

            visited.insert(u); // ����С����Ķ��������ʹ��ļ���

            for (int v = 0; v < V; ++v)
            {
                if (adjMatrix[u][v] != INT_MAX && visited.find(v) == visited.end())
                { // ���u��v��·����v�]�б��L���^
                    if (dist[v] > dist[u] + adjMatrix[u][v])
                    {                                        // �����ʼ�c��v�ľ��x�����ʼ�c��u�ľ��x����u��v�ľ��x
                        dist[v] = dist[u] + adjMatrix[u][v]; // ������ʼ�c��v�ľ��x
                        prev[v] = u;                         // ��¼ǰ���ڵ�
                    }
                }
            }
        }

        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "��ʼ�c��" << vertexName[i] << "����̾��x��: �o�����_" << endl;
            }
            else
            {
                cout << "��ʼ�c��" << vertexName[i] << "����̾��x��: " << dist[i] << endl;
                cout << "·��Ϊ: ";
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
        // vector<int> dist(V, INT_MAX);                                                       // ��ʼ�����x��o�F��
        // dist[s] = 0;                                                                        // ��ʼ�c���Լ��ľ��x��0
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // ���ȼ���У�����x����С�ľ��x
        // pq.push(make_pair(0, s));                                                           // ����ʼ�c���냞�ȼ����

        // while (!pq.empty())
        // {
        //     int u = pq.top().second; // ȡ����С���x���c
        //     pq.pop();                // ����С���x���c�ă��ȼ�����Єh��

        //     if (visited.find(u) != visited.end())
        //     {
        //         continue;
        //     }
        //     visited.insert(u); // ����С���x���c�����L���^���c

        //     for (int v = 0; v < V; ++v)
        //     {
        //         if (adjMatrix[u][v] != INT_MAX && visited.find(v) == visited.end())
        //         // ���u��v��·����v�]�б��L���^
        //         {
        //             if (dist[v] > dist[u] + adjMatrix[u][v])
        //             {                                        // �����ʼ�c��v�ľ��x�����ʼ�c��u�ľ��x����u��v�ľ��x
        //                 dist[v] = dist[u] + adjMatrix[u][v]; // ������ʼ�c��v�ľ��x
        //                 pq.push(make_pair(dist[v], v));      // ��v���냞�ȼ����
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < V; ++i)
        // {
        //     if (dist[i] == INT_MAX)
        //     {
        //         cout << "��ʼ�c��" << i << "����̾��x��: �o�����_" << endl;
        //     }
        //     else
        //     {
        //         cout << "��ʼ�c��" << i << "����̾��x��: " << dist[i] << endl;
        //     }
    }
};

int main()
{
    cout << "���Ƿ���Ҫʹ��Ĭ�ϵ�ͼ������������1����������0��" << endl;
    int flag;
    cin >> flag;
    if (flag == 1)
    {
        int V = 7; // �������
        Graph g(V);

        // ��Ӷ���
        g.addVertex("Ф������", 0);
        g.addVertex("�ܽ��׺���", 1);
        g.addVertex("����Ѹ�ڽ���Ƭ", 2);
        g.addVertex("��", 3);
        g.addVertex("����", 4);
        g.addVertex("����", 5);
        g.addVertex("��+100Ԫ", 6);

        // ��ӱ�
        g.addEdge("Ф������", "�ܽ��׺���", 0);
        g.addEdge("Ф������", "����Ѹ�ڽ���Ƭ", 50);
        g.addEdge("�ܽ��׺���", "����Ѹ�ڽ���Ƭ", 0);
        g.addEdge("����Ѹ�ڽ���Ƭ", "��", 150);
        g.addEdge("����Ѹ�ڽ���Ƭ", "����", 200);
        g.addEdge("�ܽ��׺���", "��", 300);
        g.addEdge("�ܽ��׺���", "����", 350);
        g.addEdge("��", "����", 100);
        g.addEdge("����", "����", 200);

        string s;
        s = "Ф������";
        g.dijkstra(s);
    }
    else
    {
        cout << "������ͼ�Ķ�������ͱߵĸ������Լ��ߵ���ʼ���㣬��ֹ�����Ȩ��" << endl;
        int V;
        cout << "�����붥�����:";
        cin >> V;
        Graph g(V);

        cout << "�����붥������:" << endl;
        for (int i = 0; i < V; ++i)
        {
            string name;
            cout << "���� " << i << " ������: ";
            cin >> name;
            g.addVertex(name, i);
        }
        int E;
        cout << "������ߵĸ���:";
        cin >> E;
        for (int i = 0; i < E; ++i)
        {
            string start, end;
            int w;
            cout << "������ߵ���ʼ����:";
            cin >> start;
            cout << "������ߵ���ֹ����:";
            cin >> end;
            cout << "������ߵ�Ȩ��:";
            cin >> w;
            g.addEdge(start, end, w);
        }

        string s;
        cout << "��������ʼ����:";
        cin >> s;
        g.dijkstra(s);
    }
}