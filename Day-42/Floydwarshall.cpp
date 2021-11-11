#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph = {
        {0, 5, inf, 10},
        {inf, 0, 3, inf},
        {inf, inf, 0, 1},
        {inf, inf, inf, 0}};

    int n = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == inf)
            {
                cout << "INF";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    //   shortest distance betn =1,3
    cout << dist[1][3];
    return 0;
}