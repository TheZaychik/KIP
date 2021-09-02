#include <iostream>

using namespace std;
const int intmax = 99999999; // ну просто что то плюсовые константы не оч хотят работать
const int intmin = -99999999;
const int V = 8; // кол-во вершин

void Dijkstra(int graph[V][V], int st) {
    int min_distance[V], max_distance[V], count, index, i, u, m = st + 1;
    bool min_visited[V], max_visited[V];
    for (i = 0; i < V; i++) {
        min_distance[i] = intmax;
        max_distance[i] = intmin;
        min_visited[i] = false;
        max_visited[i] = false;
    }
    min_distance[st] = 0;
    max_distance[st] = 0;

    for (count = 0; count < V - 1; count++) {
        int min = intmax;
        for (i = 0; i < V; i++) {
            if (!min_visited[i] && min_distance[i] <= min) {
                min = min_distance[i];
                index = i;
            }
        }
        u = index;
        min_visited[u] = true;
        for (i = 0; i < V; i++) {
            if (!min_visited[i] && graph[u][i] && min_distance[u] != intmax && min_distance[u] + graph[u][i] < min_distance[i])
                min_distance[i] = min_distance[u] + graph[u][i];
        }
    }

    for (count = 0; count < V - 1; count++) {
        int max = intmin;
        for (i = 0; i < V; i++) {
            if (!max_visited[i] && max_distance[i] >= max) {
                max = max_distance[i];
                index = i;
            }
        }
        u = index;
        max_visited[u] = true;
        for (i = 0; i < V; i++) {
            if (!max_visited[i] && graph[u][i] && max_distance[u] != intmin && max_distance[u] + graph[u][i] > max_distance[i])
                max_distance[i] = max_distance[u] + graph[u][i];
        }
    }
    cout << "Кратчайшие пути из начальной вершины до остальных:\t\n";
    for (i = 0; i < V; i++)
        if (min_distance[i] != intmax)
            cout << m << " > " << i + 1 << " = " << min_distance[i] << endl;
        else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
    cout << "Критические пути из начальной вершины до остальных:\t\n";
    for (i = 0; i < V; i++)
        if (max_distance[i] != intmin)
            cout << m << " > " << i + 1 << " = " << max_distance[i] << endl;
        else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}

//главная функция
int main() {
    int start, graph[V][V] = {
            {0, 2, 3, 4, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 8, 3, 0},
            {0, 0, 0, 4, 5, 0, 6, 0},
            {0, 0, 0, 0, 2, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 4, 8},
            {0, 0, 0, 0, 0, 0, 0, 6},
            {0, 0, 0, 0, 0, 0, 0, 7},
            {0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout << "Начальная вершина >> ";
    cin >> start;
    Dijkstra(graph, start - 1);
}
