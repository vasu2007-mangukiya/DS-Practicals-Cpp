#include <iostream>
#include <queue>
using namespace std;

int a[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0}};

int visited[5] = {0};

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < 5; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start)
{
    int vis[5] = {0};
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < 5; i++)
        {
            if (a[v][i] == 1 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}