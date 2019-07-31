#include <iostream>
#include <stdio.h>
#include<limits.h>
#include<tuple>

using namespace std;

#define v 9

int min_distance(int dist[v],int visited[v]);
void display(int dist[v], int parent[v]);

void dijkstra(int graph[v][v], int start){
    int m,n;
    static int dist[v];
    int visited[v];
    static int parent[v];

    for(int i=0; i<v; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start]=0;

    for(int count = 0; count < v; count++){
        m = min_distance(dist,visited);
        visited[m] = 1;

        for(n=0;n<v;n++){
            if(visited[n] == 0 && graph[m][n] != 0 && dist[n] > dist[m] + graph[m][n]){
                dist[n] = dist[m] + graph[m][n];
                parent[n] = m;
            }
        }
    }
    display(dist, parent);
}

int min_distance(int dist[v],int visited[v]){
    int min = INT_MAX;
    int min_vertex = 0;

    for(int i=0; i<v;i++){
        if(dist[i] < min && visited[i] == 0){
            min = dist[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void display(int dist[v], int parent[v]){
    //cout <<endl;
    cout<< "min distance" << "\t" << "parent" <<endl;
    for(int i=0; i<v;i++){
        cout<<dist[i]<<"\t \t \t \t"<<parent[i]<<endl;
    }

}

int main()
{
    int graph[v][v] ={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
