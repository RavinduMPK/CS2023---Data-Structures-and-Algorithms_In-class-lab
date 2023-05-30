#include <iostream>
#include <limits.h>
using namespace std;

#define V 6

int minTime(int time[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && time[v] <= min)
            min = time[v], min_index = v;

    return min_index;
}

void printSolution(int time[], int src)
{
    int sum = 0;
    cout << endl;
    cout << endl;
    cout << "   Source Node is City " << src << endl;
    cout << endl;

    cout << endl;
    for (int i = 0; i < V; i++) {
        sum += time[i];
        cout << "   Time from city " << src << " to city " << i << " = " << time[i] << endl;
        cout << endl;
    }
    cout << endl;
    cout << "   Average time to a city from city " << src << " = " << sum / (V - 1) << endl;
    cout << endl;
    cout << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int time[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        time[i] = INT_MAX, sptSet[i] = false;

    time[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minTime(time, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]
                && time[u] != INT_MAX
                && time[u] + graph[u][v] < time[v])
                time[v] = time[u] + graph[u][v];
    }

    printSolution(time, src);
}

int main()
{
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0, 0 }, };

    dijkstra(graph, 1);

    return 0;
}